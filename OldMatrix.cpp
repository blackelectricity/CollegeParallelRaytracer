#include "Matrix.h"

Matrix Matrix::identity(){
    Matrix a;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            a.array[i][j] = (i==j)?1.0:0.0;
    return a;
}
Matrix Matrix::zero(){
    Matrix a;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            a.array[i][j] = 0;
    return a;
}
Matrix Matrix::mirrorX(){
    Matrix a = identity();
    a.array[0][0] = -1;
    return a;
}
Matrix Matrix::mirrorY(){
    Matrix a = identity();
    a.array[1][1] = -1;
    return a;
}
Matrix Matrix::mirrorZ(){
    Matrix a = identity();
    a.array[2][2] = -1;
    return a;
}
Matrix Matrix::translate(const Vector& pos){
    Matrix a = identity();
    a.array[3][0] = pos.x;
    a.array[3][1] = pos.y;
    a.array[3][2] = pos.z;
    return a;
}
Matrix Matrix::scale(double x, double y, double z){
    Matrix a = identity();
    a.array[0][0] = x;
    a.array[1][1] = y;
    a.array[2][2] = z;
    return a;
}
Matrix Matrix::rotateX(double angle){
    Matrix a = identity();
    double cosa = cos(angle);
    double sina = sin(angle);
    a.array[1][1] = cosa;
    a.array[2][1] = -sina;
    a.array[1][2] = sina;
    a.array[2][2] = cosa;
    return a;
}
Matrix Matrix::rotateY(double angle){
    Matrix a = identity();
    double cosa = cos(angle);
    double sina = sin(angle);
    a.array[0][0] = cosa;
    a.array[2][0] = -sina;
    a.array[0][2] = sina;
    a.array[2][2] = cosa;
    return a;
}
Matrix Matrix::rotateZ(double angle){
    Matrix a = identity();
    double cosa = cos(angle);
    double sina = sin(angle);
    a.array[0][0] = cosa;
    a.array[1][0] = -sina;
    a.array[0][1] = sina;
    a.array[1][1] = cosa;
    return a;
}
//creates rotation matrix to rotate by 'angle' around axis 'v'
//Eric Haine's SPD
Matrix Matrix::rotateV(const Vector& v, double angle){
    Matrix a;
    double cosa = cos(angle);
    double sina = sin(angle);
    
    a.array[0][0] = v.x * v.x + (1.0 - v.x * v.x)  * cosa;
    a.array[0][1] = v.x * v.y * (1.0 - cosa) + v.z * sina;
    a.array[0][2] = v.x * v.z * (1.0 - cosa) - v.y * sina;
    a.array[0][3] = 0;
    
    a.array[1][0] = v.x * v.x * (1.0 - cosa) - v.z * sina;
    a.array[1][1] = v.y * v.y + (1.0 - v.y * v.y)  * cosa;
    a.array[1][2] = v.y * v.z * (1.0 - cosa) + v.x * sina;
    a.array[1][3] = 0;
    
    a.array[2][0] = v.x * v.z * (1.0 - cosa) + v.y * sina;
    a.array[2][1] = v.y * v.z * (1.0 - cosa) - v.x * sina;
    a.array[2][2] = v.z * v.z + (1.0 - v.z * v.z)  * cosa;
    a.array[2][3] = 0;
    
    a.array[3][0] = 0;
    a.array[3][1] = 0;
    a.array[3][2] = 0;
    a.array[3][3] = 1;
    
    return a;
}
Matrix Matrix::rotate3(const Vector& x, const Vector& y, const Vector& z){
    Matrix a = identity();
    a.array[0][0] = x.x;
    a.array[1][0] = x.y;
    a.array[2][0] = x.z;
    a.array[0][1] = y.x;
    a.array[1][1] = y.y;
    a.array[2][1] = y.z;
    a.array[0][2] = z.x;
    a.array[1][2] = z.y;
    a.array[2][2] = z.z;
    return a;
}
//nicholas wilt
Matrix Matrix::viewingMatrix(const Vector& direction,
                                    const Vector& location,
                                    const Vector& up){
    Matrix a = identity();
    Vector i,j,k;
    Vector upN = up.normalize();
    
    k = (location - direction).normalize();
    j = upN - direction;
    j -= (k * j.dot(k));
    j = j.normalize();
    i = j.cross(k);
    
    a.array[0][0] = i.x;
    a.array[1][0] = i.y;
    a.array[2][0] = i.z;
    a.array[0][1] = j.x;
    a.array[1][1] = j.y;
    a.array[2][1] = j.z;
    a.array[0][2] = k.x;
    a.array[1][2] = k.y;
    a.array[2][2] = k.z;
    
    a.array[3][0] = -(i.dot(location));
    a.array[3][1] = -(j.dot(location));
    a.array[3][2] = -(k.dot(location));
    
    return a;
}
//Foley pp. 528-529 create a matrix for quadrics? not sure what this does...
Matrix Matrix::quadricMatrix(double a, double b, double c, double d, double e,
                             double f, double g, double h, double j, double k){
    Matrix a1;
    a1.array[0][0] = a;
    a1.array[1][1] = b;
    a1.array[2][2] = c;
    a1.array[3][3] = k;
    a1.array[0][1] = a1.array[1][0] = d;
    a1.array[1][2] = a1.array[2][1] = e;
    a1.array[0][2] = a1.array[2][0] = f;
    a1.array[0][3] = a1.array[3][0] = g;
    a1.array[3][1] = a1.array[1][3] = h;
    a1.array[3][2] = a1.array[2][3] = j;
    return a1;
}      
Matrix& Matrix::operator += (const Matrix& a){
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            array[i][j] += a.array[i][j];
    return *this;
}
Matrix& Matrix::operator -= (const Matrix& a){
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            array[i][j] -= a.array[i][j];
    return *this;
}
Matrix& Matrix::operator *= (const Matrix& a){
    double rowSum;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            rowSum = 0;
            
            for(int k=0; k<4; k++)
                rowSum += array[i][k] * a.array[k][j];
                
            array[i][j] = rowSum;
        }
    }
    return *this;
}
Matrix& Matrix::operator *= (double scalar){
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            array[i][j] *= scalar;
    return *this;
}
Vector operator * (const Matrix& a, const Vector& v1){
    Vector v;
    
    v.x = v1.x * a.array[0][0] +
          v1.y * a.array[1][0] +
          v1.z * a.array[2][0] +
                 a.array[3][0];
                
    v.y = v1.x * a.array[0][1] +
          v1.y * a.array[1][1] +
          v1.z * a.array[2][1] +
                 a.array[3][1];
                 
    v.z = v1.x * a.array[0][2] +
          v1.y * a.array[1][2] +
          v1.z * a.array[2][2] +
                 a.array[3][2];
                 
    v /= (a.array[0][3] +
          a.array[1][3] +
          a.array[2][3] +
          a.array[3][3]);
    
    return v;
}
Matrix operator + (const Matrix& a1, const Matrix& a2){
    Matrix a;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            a.array[i][j] = a1.array[i][j] + a2.array[i][j];
    return a;
}
Matrix operator - (const Matrix& a1, const Matrix& a2){
    Matrix a;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            a.array[i][j] = a1.array[i][j] - a2.array[i][j];
    return a;
}
Matrix operator * (const Matrix& a1, const Matrix& a2){
    Matrix a;
    double rowSum;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            rowSum=0;
        
            for(int k=0; k<4; k++)
                rowSum += a1.array[i][k] * a2.array[k][j];
        
            a.array[i][j] = rowSum;
        }
    }
    return a;
}
Matrix operator * (const Matrix& a1, double scalar){
    Matrix a;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            a.array[i][j] = a1.array[i][j] * scalar;
    return a;
}

//only rotate the matrix don't translate from Nicholas Wilt
Vector Matrix::rotateOnly(const Vector& v1) const{
    Vector v;
    
    v.x = v1.x * array[0][0] +
          v1.y * array[1][0] +
          v1.z * array[2][0];
                
    v.y = v1.x * array[0][1] +
          v1.y * array[1][1] +
          v1.z * array[2][1];
                 
    v.z = v1.x * array[0][2] +
          v1.y * array[1][2] +
          v1.z * array[2][2];
                 
    v /= (array[0][3] +
          array[1][3] +
          array[2][3] +
          array[3][3]);
    
    return v;
}
//gaussian elimination inversion of matrix Nicholas Wilt pp 37-38
void Matrix::invert(){
    Matrix a = identity();
    int coeff;
    for(int i=0; i<4; i++){
        coeff = array[i][i];
        if(coeff!=1){
            for(int j=0; j<4; j++){
                a.array[i][j] /= coeff;
                array[i][j] /= coeff;
            }
        }
        for(int j=0; j<4; j++){
            if(i!=j){
                if(array[j][i]!=0){
                    coeff = array[j][i];
                    for(int k=0; k<4; k++){
                        array[j][k] -= coeff * array[i][k];
                        a.array[j][k] -= coeff * a.array[i][k];
                    }
                }
            }
        }
    }
    *this = a;
}
void Matrix::transpose(){
    double temp;
    for(int i=0; i<4; i++)
        for(int j=i; j<4; j++)
            if(j!=i){
                temp = array[i][j];
                array[i][j] = array[j][i];
                array[j][i] = temp;
            }
}            
Matrix Matrix::inverted() const{
    Matrix a = *this;
    a.invert();
    return a;
}
Matrix Matrix::transposed() const{
    Matrix a = *this;
    a.transpose();
    return a;
}
Matrix Matrix::rotatedOnly() const{
    Matrix a = *this;
    a.array[3][0] = 0;
    a.array[3][1] = 0;
    a.array[3][2] = 0;
    return a;
}



