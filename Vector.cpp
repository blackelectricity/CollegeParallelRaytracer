#include "Vector.h"
//self explanatory vector calculations...
Vector::Vector(){
    x= y= z= 0;
};

Vector::Vector(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
};

double Vector::magnitude() const{
    return (double)sqrt(x*x+y*y+z*z);
};

Vector Vector::normalize() const{
    return (*this / magnitude());
};

double Vector::dot(const Vector& v) const{
    return (x*v.x + y*v.y + z*v.z);
};

Vector Vector::operator - () const{
    return Vector(-x,-y,-z);
};

Vector operator + (const Vector& v1, const Vector& v2){
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
};

Vector operator - (const Vector& v1, const Vector& v2){ 
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); 
};

Vector operator * (const Vector& v1, const Vector& v2){ 
    return Vector(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z); 
};

Vector operator * (double scalar, const Vector& v){
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar); 
};

Vector operator * (const Vector& v, double scalar){
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar); 
};

Vector operator / (const Vector& v, double scalar){
    return Vector(v.x / scalar, v.y / scalar, v.z / scalar);
};


