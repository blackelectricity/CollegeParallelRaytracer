#ifndef RAY_H
#define RAY_H

//a ray has a vector for a starting position: (location)
//and a normalized direction vector

class Ray{
public:
    Ray(const Vector& location, const Vector& direction);

    //return a vector which is equal to magnitude*direction + location
    Vector extrapolate(float magnitude) const;

    //returns a vector which was reflected of a surface by a normal vector
    Vector reflect(const Vector& normal) const;

    //holds location and direction of a ray
    Vector location, direction;
};    
#endif
