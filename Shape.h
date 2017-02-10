#ifndef SHAPE_H
#define SHAPE_H

//abstract class which all intersectable objects should implement
class Shape{
public:
    //all shapes must be intersectable or they don't visually exist
    //virtual method to intersect a ray with a shape given that the
    //ray can only go to max_distance otherwise returns a MISS
    virtual IntersectEnum intersect(Ray&, double& max_distance) = 0;

    //returns the normal vector to any position on the shape
    //the position is represented by a vector
    virtual Vector normal(const Vector&) = 0;

    //deconstruct the shape
    ~Shape(){delete material;}
    
    //stores the surface for the shape (diffuse, ambient, color, etc...)
    Surface* material;
};
#endif
