#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

class Matrix{
public:
    double array[4][4];
    
    Matrix(){}
    
    //generic matrices (static methods)
    static Matrix identity     ();
    static Matrix zero         ();
    static Matrix translate    (const Vector&);
    static Matrix scale        (double x, double y, double z);   
    static Matrix mirrorX      ();
    static Matrix mirrorY      ();
    static Matrix mirrorZ      ();
    static Matrix rotateX      (double angle);
    static Matrix rotateY      (double angle);
    static Matrix rotateZ      (double angle);
    static Matrix rotateV      (const Vector& v, double angle);
    
    static Matrix rotate3      (const Vector& x,
                                const Vector& y,
                                const Vector& z);
                                
    static Matrix viewingMatrix(const Vector& direction, const Vector& location,
                                const Vector& up);
                         
    static Matrix quadricMatrix(double, double, double, double, double,
                                double, double, double, double, double);
    
    //assignment
    Matrix& operator += (const Matrix&);
    Matrix& operator -= (const Matrix&);
    Matrix& operator *= (const Matrix&);
    Matrix& operator *= (double);
    
    //binary
    friend class Vector operator * (const Matrix&, const Vector&);
    friend Matrix operator + (const Matrix&, const Matrix&);
    friend Matrix operator - (const Matrix&, const Matrix&);
    friend Matrix operator * (const Matrix&, const Matrix&);
    friend Matrix operator * (const Matrix&, double);
    
    //matrix vector math
    Vector rotateOnly(const Vector&) const;
    
    //mutate
    void   invert       ();
    void   transpose    ();
    
    //const-functions return new mutated matrix
    Matrix inverted     () const;
    Matrix transposed   () const;  
    Matrix rotatedOnly  () const;
};    
#endif
