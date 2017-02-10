#include "Ray.h"

using namespace std;

Ray::Ray(const Vector& location, const Vector& direction){
    this->direction = direction.normalize();
    this->location = location;
};

Vector Ray::extrapolate(float magnitude) const {
    return location + direction * magnitude;
}; 
  
Vector Ray::reflect(const Vector& normal) const{
    //reflects a ray off of a surface with its 'normal' vector
    return (normal * 2 * normal.dot(-direction) + direction).normalize();
};


