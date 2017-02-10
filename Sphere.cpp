#include "Sphere.h"

Sphere::Sphere(const Vector center, double radius, Surface* material){
    this->radius = radius;
    this->radiusSquared = radius*radius;
    this->center = center;
    this->material = material;
};


//calculate ray's intersection from outside of sphere and adjust distance
IntersectEnum Sphere::intersect(Ray& r, double& dist){
    //math taken from Jacco Bikker, also known as 'Phantom'
    Vector v = center - r.location;
    double c = v.dot(v) - radiusSquared;
    double b = -2 * v.dot(r.direction);
    double d = b*b - 4*c;
    if (d <= 0) return MISS;
    d = sqrt(d);
    double t1 = (-b+d)/2.0;
    double t2 = (-b-d)/2.0;
    if (t1 < 0 || t1 > dist && t2 < 0 || t2 > dist) return MISS;
    (t2 < 0) ? dist = t1 : dist = (t1 < t2) ? t1 : t2;    
    return (dist > 0) ? HIT : MISS;
};

//normal vector is vector from center to the intersection point!
Vector Sphere::normal(const Vector& v){
    return (v-center).normalize();
};
