#ifndef PLANE_H
#define PLANE_H

/*class to create a 2 dimensional plane perpendicular to the normal_v Vector
^+y axis
|
|        ^
|        |  <--normal vector (0, 0, 600)
|        |
|        |       v-- top (see surface for qualities)
|<------------------------------------------------------> <--plane located at: 
|                ^-- bottom (clear)                     -600y facing positive y
|
|
|
|
V-y axis
The position of the plane is normal's magnitude along normal vector from origin
*/
class Plane : Shape{
public:
    //creates a plane with a normal vector and a surface
    Plane(const Vector plane, Surface* material);

    //returns HIT or MISS and modifies distance
    //if plane is farther away than distance, it will MISS
    IntersectEnum intersect(Ray&, double& distance);

    //returns the plane's normal vector
    Vector normal(const Vector&);


private:
    Vector normal_v;
    double magnitude;
};
#endif
