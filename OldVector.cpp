#include "Vector.h"

Vector::Vector(){
    x= y= z= 0;
}
Vector::Vector(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
}
Vector::Vector(const Vector& v){
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}
void Vector::set(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
}
double Vector::magnitude() const{
    return (double)sqrt(x*x+y*y+z*z);
}
double Vector::squared() const{
    return (x*x+y*y+z*z);
}
Vector Vector::normalize() const{
    return (*this / magnitude());
}
void Vector::shrink(const Vector& v){
    if (v.x < x) x = v.x;
    if (v.y < y) y = v.y;
    if (v.z < z) z = v.z;
}
void Vector::grow(const Vector& v){
    if (v.x > x) x = v.x;
    if (v.y > y) y = v.y;
    if (v.z > z) z = v.z;
}
double Vector::dot(const Vector& v) const{
    return (x*v.x + y*v.y + z*v.z);
}
Vector Vector::cross(const Vector& v) const{
    return Vector(y*v.z - z*v.y,
                  z*v.x - x*v.z,
                  x*v.y - y*v.x);
}
Vector Vector::operator - () const{
    return Vector(-x,-y,-z);
}
Vector Vector::operator + () const{
    return *this;
}
double& Vector::operator [] (int index){
    switch(index){
        case 0:
            return x;
        case 1:
            return y;
        default:
            return z;
     }
}      
const double& Vector::operator [] (int index) const{   
    switch(index){
        case 0:
            return x;
        case 1:
            return y;
        default:
            return z;
     }
}
Vector& Vector::operator += (const Vector& v){
    x+=v.x;
    y+=v.y;
    z+=v.z;
    return *this;
}
Vector& Vector::operator -= (const Vector& v){
    x-=v.x;
    y-=v.y;
    z-=v.z;
    return *this;
}
Vector& Vector::operator *= (const Vector& v){
    x*=v.x;
    y*=v.y;
    z*=v.z;
    return *this;
}
Vector& Vector::operator /= (const Vector& v){
    x/=v.x;
    y/=v.y;
    z/=v.z;
    return *this;
}
Vector& Vector::operator += (double scalar){
    x+=scalar;
    y+=scalar;
    z+=scalar;
    return *this;
}
Vector& Vector::operator -= (double scalar){
    x-=scalar;
    y-=scalar;
    z-=scalar;
    return *this;
}
Vector& Vector::operator *= (double scalar){
    x*=scalar;
    y*=scalar;
    z*=scalar;
    return *this;
}
Vector& Vector::operator /= (double scalar){
    x/=scalar;
    y/=scalar;
    z/=scalar;
    return *this;
}
Vector operator + (const Vector& v1, const Vector& v2){
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}
Vector operator - (const Vector& v1, const Vector& v2){ 
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); 
}
Vector operator * (const Vector& v1, const Vector& v2){ 
    return Vector(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z); 
}
Vector operator / (const Vector& v1, const Vector& v2){
    return Vector(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}
Vector operator * (double scalar, const Vector& v){
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar); 
}
Vector operator * (const Vector& v, double scalar){
    return Vector(v.x * scalar, v.y * scalar, v.z * scalar); 
}
Vector operator / (const Vector& v, double scalar){
    return Vector(v.x / scalar, v.y / scalar, v.z / scalar);
}
bool operator < (const Vector& v1, const Vector& v2){
    return ((v1.x < v2.x) && (v1.y < v2.y) && (v1.z < v2.z));
}
bool operator > (const Vector& v1, const Vector& v2){
    return ((v1.x > v2.x) && (v1.y > v2.y) && (v1.z > v2.z));
}
bool operator == (const Vector& v1, const Vector& v2){
    return ((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z));
}

