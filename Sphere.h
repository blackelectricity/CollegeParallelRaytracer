#ifndef SPHERE_H
#define SPHERE_H

class Sphere : Shape{
public:
    //creates sphere with center represented by vector, a radius, and a surface
    Sphere(const Vector center, double radius, Surface* material);

    IntersectEnum intersect(Ray&, double& max_distance);
    Vector normal(const Vector& v);
    
    //stores center
    Vector center;
    
    //stores radius and precomputed radiusSquared
private:
    double radius;
    double radiusSquared;
};
#endif
