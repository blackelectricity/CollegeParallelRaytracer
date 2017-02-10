#ifndef VECTOR_H
#define VECTOR_H

class Vector{
public:

    Vector (); //initialized as origin
    Vector (double x, double y, double z);

    //vector calculations
    double  magnitude () const; //returns the magnitude
    Vector  normalize () const; //returns a new normalized vector
    
    //dot product of this vector with v
    double  dot       (const Vector& v) const;
    
    //OPERATOR OVERLOADING
    Vector operator -   () const;

    //returns the result of vector math on two vectors
    friend Vector operator + (const Vector&, const Vector&);
    friend Vector operator - (const Vector&, const Vector&);
    friend Vector operator * (const Vector&, const Vector&); 
    
    //returns the result of vector math on a vector and a scalar
    friend Vector operator * (double, const Vector&);
    friend Vector operator * (const Vector&, double);
    friend Vector operator / (const Vector&, double);


private:
    //store vector components
    double x,y,z;
};    
#endif

