#ifndef SURFACE_H
#define SURFACE_H


//stores the color and shading attributes of a shape (or light)...
//self-explanatory really....
class Surface{
public:
    Surface(double ambi, double diff, double spec, int spec_pow,
            double refl, double refr, double r,
            double g,    double b,    bool is_light){
        this->rgb[0] = r;
        this->rgb[1] = g;
        this->rgb[2] = b;
        this->ambi[0]= r * ambi;
        this->ambi[1]= g * ambi;
        this->ambi[2]= b * ambi;
        this->diffuse=diff;
        this->diff[0]= r * diff;
        this->diff[1]= g * diff;
        this->diff[2]= b * diff;
        this->speculr=spec;
        this->specpow=spec_pow;
        this->spec[0]= r * spec;
        this->spec[1]= g * spec;
        this->spec[2]= b * spec;
        this->refl   = refl;
        this->refr   = refr;
        this->is_light = is_light;
    };
    
 
    double ambi[3];  //ambient factor * rgb values
    double diff[3];  // ^^^^    diffuse
    double spec[3];  // ^^^^    specular
    double diffuse;  //diffuse factor
    double speculr;  //specular factor (amount of contribution)
    int specpow;     //specular power  (density of specular highlight)
    double refl;     //reflection factor
    double refr;     //refraction factor
    double rgb[3];   //color of surface
    bool is_light;   //is this surface a light or not?
};
#endif
