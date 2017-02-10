#ifndef VECTOR_H
#define VECTOR_H

class Vector{
public:

    //OBJECT VARIABLES
    //store vector components
    double x,y,z;
    

    //CONSTRUCTORS
    Vector (); //initialize components as zero vector (origin)
    Vector (double x, double y, double z);
    Vector (const Vector&);  //copy components from another vector


    //set x,y, and z component of the vector
    void   set       (double x, double y, double z);    
    
    //vector calculations
    double  magnitude () const; //returns the magnitude (length) of the vector
    double  squared   () const; //returns magnitude * magnitude
    Vector  normalize () const; //returns a new vector with normalized components
    
    //vector math...
    double  dot       (const Vector&) const;
    Vector cross     (const Vector&) const;
    
    
    //OPERATOR OVERLOADING
    Vector operator -   () const;
    Vector operator +   () const; 
    
    //return x,y,z for [0,1,2]
    double& operator []  (int);      
    const double& operator [] (int) const;   
    
    changes object according to other vector
    Vector& operator += (const Vector&);
    Vector& operator -= (const Vector&);
    Vector& operator *= (const Vector&);
    Vector& operator /= (const Vector&);
    
    changes object according to scalar
    Vector& operator += (double);
    Vector& operator -= (double);
    Vector& operator *= (double);
    Vector& operator /= (double);

    //returns the result of vector math on two vectors
    friend Vector operator + (const Vector&, const Vector&);
    friend Vector operator - (const Vector&, const Vector&);
    friend Vector operator * (const Vector&, const Vector&); 
    friend Vector operator / (const Vector&, const Vector&);
    
    //returns the result of vector math on a vector and a scalar
    friend Vector operator * (double, const Vector&);
    friend Vector operator * (const Vector&, double);
    friend Vector operator / (const Vector&, double);

    //returns boolean value of expression on all components of two vectors
    //e.g. less than: (v1.x < v2.x) && (v1.y < v2.y) && (v1.z < v2.z)
    friend bool operator <   (const Vector& v1, const Vector& v2);
    friend bool operator >   (const Vector&, const Vector&);
    friend bool operator ==  (const Vector&, const Vector&);

};    
#endif

