#include "Server.h"

//create scene and image
Server::Server(int width1, int height1){
    width = width1;
    height = height1; 
    image = (unsigned char *)malloc(width*height*4);
    scene = new Scene();
};

//returns computed image
unsigned char* Server::get_image(){
    return image;
};

//returns next row of pixels to work on
//synchronized
int Server::get_work(){
    //acquire(1)
    semop(sem_id, &WaitMutex, 1);

        //synchronized block
        //use row_number so that it can be returned
        //outside of synchronized block
        int row_number = row_count;

        //display percentage of image assigned for work
        //complete when height is reached 
        //(more work is still assigned to kill threads: returned row>=height)
        if(row_number <= height)  
            cout << row_number/(double)height*100 << "% finished" << endl;

        //increment concurrently volatile variable
        row_count++;

        //end synchronized block
    //release(1)
    semop(sem_id, &SignalMutex, 1);

    //returning row_count would be accessing it outside
    //synchronized access
    return row_number; 
};

void Server::ray_trace(){

    //get number of processors and create threads
    int np = 2 * (int)sysconf(_SC_NPROCESSORS_CONF);
    pthread_t threads[np];

    //initialize row_number of pixels to be assigned
    //protected in get_work by a semaphore
    row_count = 0;

    //create semaphore for protecting row_count
    key_t key1;
    sem_id = semget(key1, 1, ( 0200 | 0400 | IPC_CREAT ));
    if (sem_id == -1){
        perror("semget");
        exit(-1);
    }
    semun initvar;
    initvar.val=1;
    semctl(sem_id, 0, SETVAL, initvar);

    //create threads, passing them this object
    //threads call the thread_trace function
    for(int i=0; i<np; i++)
        if (pthread_create(&(threads[i]), NULL, 
                (void *(*)(void *)) &thread_trace, 
                (void *) this) != 0){
        	perror("pthread_create"), exit(1); 
        }
    
    //wait for threads to terminate before finishing
    //image is rendered when all threads are finished
    for(int i=0; i<np; i++)
      if (pthread_join(threads[i], NULL) != 0)
    	perror("pthread_join"),exit(1);

    //destroy the semaphore
    semctl(sem_id, 0, IPC_RMID);
};

//thread function gets rows to work on and has scene render them
//creates additional rays as well for anti-aliasing purposes
void thread_trace(void* server){

    //get members of the server object
    unsigned char* image = ((Server*)server)->image;
    Scene *scene = ((Server*)server)->scene;
    int width = ((Server*)server)->width;
    int height = ((Server*)server)->height;

    //looping vars
    int i,j,k,l;

    //array for scene to trace rays and accumulate colors
    double rgb[3];

    //stores starting position of image
    unsigned char *old=image;

    //get a row to render
    i = ((Server*)server)->get_work();
    //rendering complete when row to render is >= height of screen
    while(i<height){
        //adjust image pointer to particular row
        image = old+i*width*4;

        //for every column in screen
        for(j=0; j<width; j++){
                //set initial values to 0 to start accumulation
                rgb[0]=rgb[1]=rgb[2]=0;

                //anti-alias
                //adjust ray for the mathematical coordinates of
                //ray tracer (see Scene.cpp)
                double x = (j-width/2.0);
                double y = -(i-height/2.0);

                //create rays for pixel
                for(k=0; k<ANTIALIAS; k++)
                for(l=0; l<ANTIALIAS; l++){
                        //determine small partition away from pixel
                        double sliceX =(double)k/ANTIALIAS;
                        double sliceY =(double)l/ANTIALIAS;
        
                        //create direction vector from camera 
                        //through adjusted screen pixel coordinate
                        Vector direction = 
                                    Vector(x+sliceX,y+sliceY, 0)-scene->camera;

                        //create ray from camera with direction vector
                        Ray ray = Ray(scene->camera, direction);

                        //set max distance & recursion for scene and 
                        //trace the ray through the scene
                        double dist = MAX_DISTANCE;
                        double recursion_depth = RECURSION;
                        scene->trace(ray, rgb, dist, 0, recursion_depth);
                }
                double aliasSqrd = ANTIALIAS*ANTIALIAS;
                //divide color by number of accumulated rays for average
                rgb[2] = (int)(rgb[2]/(double)(aliasSqrd));
                rgb[1] = (int)(rgb[1]/(double)(aliasSqrd));
                rgb[0] = (int)(rgb[0]/(double)(aliasSqrd));

                //limit color to 255
                rgb[2] = (rgb[2] > 255) ? 255 : rgb[2];
                rgb[1] = (rgb[1] > 255) ? 255 : rgb[1];
                rgb[0] = (rgb[0] > 255) ? 255 : rgb[0];

                //edit image array for pixel
                *image++=rgb[2]; //blue
                *image++=rgb[1]; //green
                *image++=rgb[0]; //red
                 image++;
        }
        //get next row of work to be done
        i = ((Server*)server)->get_work();
    }
};



