#include "Plane.h"

Plane::Plane(const Vector plane, Surface* material){
    this->magnitude = plane.magnitude();
    this->normal_v = plane.normalize();
    this->material = material;
};

IntersectEnum Plane::intersect(Ray& r, double& dist){

    //find dot product of ray with normal vector
	double dot = normal_v.dot(r.direction);

    //plane is or theta > 180 ray will not hit plane
	if (dot > 0) return MISS;

    //if distance is between zero and max distance change dist and return HIT
	double temp_dist = (-magnitude - normal_v.dot(r.location)) / dot;
	if (temp_dist <= 0 || temp_dist > dist) return MISS;
    dist = temp_dist;
    return HIT;
};

Vector Plane::normal(const Vector& v){
    return normal_v;
};

