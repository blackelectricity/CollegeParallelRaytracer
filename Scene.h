#ifndef SCENE_H
#define SCENE_H

class Scene{
public:
    Scene();
    ~Scene(){for(int i=0; i<num_shapes; i++) delete (shapes[i]);};

    //trace a ray through a scene and edit the rgb values
    void trace(Ray& ray, double* rgb, double& max_dist,
                                int current_depth, int max_depth);

    //camera position
    Vector camera;
private:

    //number of lights in scene
    int num_lights;

    //array of shape*'s for scene shapes
    //shapes[0]-shapes[num_lights-1] are shape* to light sources
    Shape** shapes;

    //number of shapes in scene
    int num_shapes;
};
#endif
