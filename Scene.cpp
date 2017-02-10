#include "Scene.h"

    /*
        if you are looking at the screen in the usual way you are seeing
                                ^ y
                                |
                                |
            -x<---------------center-------------->x
                                |
                                |
                                v

        the screen is located with it's center at the origin (x,y,z=0)
        you are looking into the positive z axis from the negative z axis
        the coordinates of the screen are:
        top-left: (-width, height,0)
        bottom-right: (width, -height,0) 
        center: (0,0,0)
    */


//create scene
Scene::Scene(){
    //sets camera position
    camera = Vector(0,0,-925);

//SCENE 1 ----------------------------------------------------------------
/*
    //define number of shapes and lights and create array of shapes
    num_shapes = 21;
    num_lights = 4;
    shapes = new Shape*[num_shapes];

    //create lights' surfaces
    Surface* light1 = new Surface(1,0,0,0,0,0, 255,  0,   0,   true);
    Surface* light2 = new Surface(1,0,0,0,0,0, 0,    0,   255, true);
    Surface* light3 = new Surface(1,0,0,0,0,0, 255,  88,  88,  true);
    Surface* light4 = new Surface(1,0,0,0,0,0, 88,   255, 88,  true);

    //create lights
    shapes[0] = (Shape*)new Sphere(Vector(-120, 0,  -80),   3, light2);
    shapes[1] = (Shape*)new Sphere(Vector(200,  120, 80),   3, light1);
    shapes[2] = (Shape*)new Sphere(Vector(-300, 300, 300),  3, light3);
    shapes[3] = (Shape*)new Sphere(Vector(300,  300, 300),  3, light4);
    
    //create walls' surfaces
    Surface* top_plane    = new Surface(.1, .02, .05,  50, .7, 0, 
                                255, 0,   255, false);
    Surface* bottom_plane = new Surface(.1, .02, .05,  50, .7, 0, 
                                255, 0,   0,   false);
    Surface* back_plane   = new Surface( 0, .01, .1,  100,  1, 0, 
                                33,  33,  33,  false);
    Surface* right_plane  = new Surface(.1, .02, .05,  50, .7, 0, 
                                0,   0,   255, false); 
    Surface* left_plane   = new Surface(.1, .02, .05,  50, .7, 0, 
                                0,   255, 0,   false);
    Surface* front_plane  = new Surface( 0, .01, .1,  100,  1, 0, 
                                0,   0,   0,   false);  

    //create walls
    shapes[15] = (Shape*)new Plane(Vector(   0,-450,   0),   top_plane   );
    shapes[16] = (Shape*)new Plane(Vector(   0, 450,   0),   bottom_plane);
    shapes[17] = (Shape*)new Plane(Vector(   0,   0,-600),   back_plane  );
    shapes[18] = (Shape*)new Plane(Vector(-600,   0,   0),   right_plane );
    shapes[19] = (Shape*)new Plane(Vector( 600,   0,   0),   left_plane  );
    shapes[20] = (Shape*)new Plane(Vector(   0,   0, 100),   front_plane );

    //create spheres' surfaces
    Surface* sphere1  = new Surface(.1,.4,.5,100, .2, 0, 0,   0,   255, false);
    Surface* sphere2  = new Surface(.1,.4,.5,20,  .2, 0, 0,   255, 0,   false);
    Surface* sphere3  = new Surface(.1,.4,.5,100,  0, 0, 0,   0,   0,   false);
    Surface* sphere4  = new Surface(.1,.1,.9,150, .9, 0, 255, 255, 0,   false);
    Surface* sphere5  = new Surface(.1,.2, 0,0,   .9, 0, 255, 255, 255, false);
    Surface* sphere6  = new Surface(0,  0, 0,0,   .3,.9, 255, 0,   255, false);
    Surface* sphere17 = new Surface(0, .1, 0,0,   .6,.9, 0,   0,   255, false);
    Surface* sphere19 = new Surface(0,.05,.1,200,  0,.9, 255, 0,   255, false);
    Surface* sphere20 = new Surface(0, .1,.8,200, .2,.9, 255, 0,   255, false);
    Surface* sphere21 = new Surface(0, .1,.8,200, .2,.9, 255, 0,   255, false);
    Surface* sphere7  = new Surface(.1,.4,.5,10,  .4, 0, 255, 255, 255, false);
    
    //create spheres
    shapes[4]  = (Shape*)new Sphere(Vector(-350,  300, 550), 25,  sphere7);
    shapes[5]  = (Shape*)new Sphere(Vector( -20,  250, 160), 90,  sphere1);
    shapes[6]  = (Shape*)new Sphere(Vector( 200,   10, 200), 75,  sphere2);
    shapes[7]  = (Shape*)new Sphere(Vector( 325,  -20, 100), 50,  sphere5);
    shapes[8]  = (Shape*)new Sphere(Vector( 250,  260, 420), 60,  sphere6);
    shapes[9]  = (Shape*)new Sphere(Vector(-100, -100, 100), 40,  sphere3);
    shapes[10] = (Shape*)new Sphere(Vector(-300,  120,  75), 75,  sphere4);
    shapes[11] = (Shape*)new Sphere(Vector(-250, -300, 100), 20, sphere17);
    shapes[12] = (Shape*)new Sphere(Vector(  50,    0, 160), 60, sphere19);
    shapes[13] = (Shape*)new Sphere(Vector(   0, -320, 280), 60, sphere20);
    shapes[14] = (Shape*)new Sphere(Vector(  60, -270, 350), 60, sphere21);   
*/

//SCENE 2-----------------------------------------------------------------
    //define number of shapes and lights and create array of shapes
    num_shapes = 6;
    num_lights = 3;
    shapes = new Shape*[num_shapes];

    //create light's surface
    Surface* light1 = new Surface(1,0,0,0,0,0, 255, 0, 0, true);
    Surface* light2 = new Surface(1,0,0,0,0,0, 0, 0, 255, true);
    Surface* light3 = new Surface(1,0,0,0,0,0, 0, 255, 0, true);

    //create light
    shapes[0] = (Shape*)new Sphere(Vector(0,    40,  400), 10, light1);
    shapes[1] = (Shape*)new Sphere(Vector(100,  200, 300), 10, light1);
    shapes[2] = (Shape*)new Sphere(Vector(-100, 210, 200), 10, light1);

    //create walls' surfaces
    Surface* floor_plane = new Surface(.1,.3,.2,50,.9,0,255,0,255,false);
    Surface* back_plane  = new Surface(0, .1,.8,3, .9,0,255,0,0,  false);

    //create walls
    shapes[3] = (Shape*)new Plane(Vector(0, 400, 0), floor_plane);
    shapes[4] = (Shape*)new Plane(Vector(0, 0, -1600), back_plane);

    //create sphere's surface
    Surface* sphere1  = new Surface(.1,.4,.5,100, .5, 0, 0, 0, 255, false);

    //create sphere
    shapes[5]  = (Shape*)new Sphere(Vector(0,  -150, 450), 140,  sphere1);
};

void Scene::trace(Ray& ray, double* rgb, double& dist, int depth, int max_depth)
{
    //find nearest intersected object
    IntersectEnum collide = MISS;
    Shape* iShape;
    for(int i=0; i<num_shapes; i++)
        if(shapes[i]->intersect(ray, dist) == HIT){
            collide = HIT;
            iShape = shapes[i]; //nearest object saved in iShape
        }
    
    //hit no objects
    if(collide == MISS) return;
    
    //hit a light
    if((*iShape).material->is_light){
        rgb[0] += (*iShape).material->rgb[0];
        rgb[1] += (*iShape).material->rgb[1];
        rgb[2] += (*iShape).material->rgb[2];
        return;
    }
  
    //add ambient lighting
    rgb[0] += (*iShape).material->ambi[0];
    rgb[1] += (*iShape).material->ambi[1];
    rgb[2] += (*iShape).material->ambi[2];

    //calculate needed vectors
    Vector view   = ray.extrapolate(dist);     //point of intersection
    Vector normal = (*iShape).normal(view);    //normal of shape
    Vector view_reflect = ray.reflect(normal); //direction of reflected ray
    
    //apply diffuse and specular for each light in scene
    for(int i=0; i < num_lights; i++){
        //note: lights are shapes[0] - shapes[num_lights-1]
        Vector light  = ((*(Sphere *)shapes[i]).center - view);
        
        //determine shade
        double shade = 1;
        double light_dist = light.magnitude();
        //create ray from intersection to light
        Ray light_ray = Ray(view + normal * .0001, light); 

        //if an object blocks ray the point of intersection is in a shadow
        for(int ix=num_lights; ix<num_shapes; ix++)
            if(shapes[ix]->intersect(light_ray, light_dist) == HIT){
                shade = 0;
        }   
        
        //determine diffuse+specular
        light = light.normalize();  //normalize light vector b4 dot products
        
        //calculate diffuse amount
        //(diffuse is calculated from objects' normal vector)
        double diffuse = light.dot(normal);  if (diffuse < 0) diffuse = 0;
        
        //calculate specular amount (with angle between light &reflected)
        //this takes into respect the angle of the camera in the highlights
        //if diffuse = 0 prevent wrong speculr highlights from inside of surface
        //if speculr factor < 0 don't calculate specular information
        double speculr;
        double specPower;   
        if (speculr<0||diffuse==0){
            speculr = 0;
            specPower = 0;
        }else{
            speculr = light.dot(view_reflect);
            specPower = (*iShape).material->specpow;  
        }

        //for r, g, and b of rgb add the specular and diffuse amounts
        for(int ix = 0; ix < 3; ix++){
            //diffuse  (with more color from object and light)
            rgb[ix] += shade * diffuse * ((*(shapes[i])).material->rgb[ix] 
                                  * (*iShape).material->diffuse
                                  +(*iShape).material->diff[ix]);
                                  
            //specular (with color coming from light) (if ray is camera spawned)
            if(depth==0) rgb[ix] += shade * 
                      powf(speculr, (*iShape).material->specpow)*
                      ((*(shapes[i])).material->rgb[ix]*
                      (*iShape).material->speculr);
                      
        }
            
    }
    
    //if maximum recursion return only ambient, diffuse, and specular light
    if (depth == max_depth) return;
    
    //reflections
    if((*iShape).material->refl > 0){
        //create ray from reflected vector
        Ray refl_ray = Ray(view + normal*.1, view_reflect);

        //get color from new ray through trace algorithm recursively
        double refl_rgb[3];
        refl_rgb[0]=0;
        refl_rgb[1]=0;
        refl_rgb[2]=0;
        dist = MAX_DISTANCE;
        trace(refl_ray, refl_rgb, dist, depth+1, max_depth);

        //add color components times influence factor determined by recursion
        for(int ix=0; ix<3; ix++)
            rgb[ix]+=(*iShape).material->refl*refl_rgb[ix]*
                ((max_depth-depth)/(double)max_depth);
    }   
    
    //refractions (only spheres supported)
    double ref = (*iShape).material->refr;
    if(ref > 0){
        //determine vector refracted into sphere
        double cos1 = -normal.dot(ray.direction);
        double into_ref = .7;
        double cos2 = sqrt(1-into_ref*into_ref*(1-cos1*cos1));
        Vector t = into_ref * ray.direction + (into_ref*cos1 - cos2)*normal;

        //create ray from refracted vector (into the sphere)
        Ray refr_ray = Ray(view + t*.001, t);
        dist = MAX_DISTANCE;

        //find where new refracted vector intersects within the sphere
        (*iShape).intersect(refr_ray, dist);

        //determine vector refracted out of sphere
        Vector new_view = refr_ray.extrapolate(dist);
        Vector new_norm = (*iShape).normal(new_view);
        cos1 = new_norm.dot(refr_ray.direction);
        into_ref = 1.4;
        cos2 = sqrt(1-into_ref*into_ref*(1-cos1*cos1));
        t = into_ref * refr_ray.direction + (into_ref*cos1 -cos2)*new_norm;

        //create ray from refracted vector (into the outside world)
        refr_ray = Ray(new_view + t*.001, t);

        //recursively trace the new refracted ray
        dist = MAX_DISTANCE;
        double refr_rgb[3];
        refr_rgb[0]=refr_rgb[1]=refr_rgb[2]=0;
        trace(refr_ray, refr_rgb, dist, depth+1, max_depth);

        //add color compontents times influence factor determined by recrusion
        for(int ix=0; ix<3; ix++)
            rgb[ix]+=ref*refr_rgb[ix]*((max_depth-depth)/(double)max_depth);
    }
};

