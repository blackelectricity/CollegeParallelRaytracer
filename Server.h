#ifndef SERVER_H
#define SERVER_H

//during intersection hit = intersected, miss = no intersection
enum IntersectEnum  {HIT, MISS};

#include "Vector.cpp"
#include "Ray.cpp"
#include "Surface.h"
#include "Shape.h"
#include "Sphere.cpp"
#include "Plane.cpp"
#include "Scene.cpp"


//struct definition used to create semaphore
typedef union {
    int val;
    struct semid_ds *buf;
    ushort *array;
} semun;

//structs to modify semaphore (used for c++ equivalent require/release)
struct sembuf WaitMutex = {0, -1, 0};
struct sembuf SignalMutex = {0, 1, 0};

//declare method since definitino appears later than use
void thread_trace(void*);

//is responsible for dividing the work of rendering the image
//and anti-aliasing in a concurrent fashion
class Server {
public:
    //creates a new server
    Server(int width, int height);

    //starts the computation which edits image
    void ray_trace();

    //returns the edited image
    unsigned char* get_image();

    //returns the row of pixels to render
    int get_work();  //thread safe
    
    //stores the picture
    unsigned char* image;
    //stores the screen properties
    int width, height;
    //stores the scene which is rendered (objects, surfaces...)
    Scene *scene;


private:
    //protects get_work method
    int sem_id;
    //counts rows of pixels edited for get_work
    int row_count;
}; 

#endif
