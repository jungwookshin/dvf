// author: Jungwook Shin @ mgh (jshin13@mgh.harvard.edu)

#ifndef RTI_VEC_H
#define RTI_VEC_H

#include <cmath>
#include <iostream>

#include "rti_common.hpp"

//names?
//point: vec2, vec3
//line: line2d, line3d
//surface: rect2d, rect
//volume: cell3d, hexa (cell3d)

namespace rti{
template<typename T> 
class vec2 {
public:
    //
    T x;
    T y;

    CUDA_HOST_DEVICE
    vec2(vec2& ref){
        x = ref.x;
        y = ref.y;
    }

    CUDA_HOST_DEVICE
    vec2(): x(0), y(0){;}

    CUDA_HOST_DEVICE
    vec2(T a, T b): x(a), y(b){;}

    CUDA_HOST_DEVICE
    vec2(const vec2& ref ): x(ref.x), y(ref.y){;}

    CUDA_HOST_DEVICE
    vec2(const std::array<T,2>& ref ): x(ref[0]), y(ref[1]){;}
    //#endif

    CUDA_HOST_DEVICE
    ~vec2(){;}

    CUDA_HOST_DEVICE
    #if defined(__CUDACC__)
    //sqrtf : for float, sqrtg: for double
    T norm()const{return sqrtf(x*x+y*y);}
    #else
    T norm()const{return std::sqrt(x*x+y*y);}
    #endif
    

    CUDA_HOST_DEVICE
    vec2<T>&
    operator= 
    (const vec2<T>& r){
        x = r.x ; y = r.y;
        return *this;
    }

    CUDA_HOST_DEVICE
    vec2<T>
    operator + 
    (const vec2<T>& r)const{
        return vec2<T>(x+r.x, y+r.y);
    }

    CUDA_HOST_DEVICE
    vec2<T>
    operator - 
    (const vec2<T>& r)const{
        return vec2<T>(x-r.x, y-r.y);
    }

    CUDA_HOST_DEVICE
    vec2<T> 
    operator * 
    (const T& r)const{
        return vec2<T>(x*r, y*r);
    }

    CUDA_HOST_DEVICE
    template<typename R>
    vec2<T> 
    operator * 
    (const R& r)const{
        return vec2<T>(x*r, y*r);
    }

    CUDA_HOST_DEVICE
    vec2<T> 
    operator * 
    (const vec2<T>& r)const{
        return vec2<T>(x*r.x, y*r.y);
    }

    CUDA_HOST_DEVICE
    void dump() const {
        #if defined(__CUDACC__)
        /*
        printf("xx,xy,xz %f, %f, %f\n", xx,xy, xz);
        printf("yx,yy,yz %f, %f, %f\n", yx,yy, yz);
        printf("zx,zy,zz %f, %f, %f\n", zx,zy, zz);
        */
        #else
        std::cout<<"x,y: ("<< x <<", " << y <<") " << std::endl;
        #endif
    }
    
};


//this is a copy of HepRotation.
template<typename T> 
class vec3 {
public:
    //
    T x;
    T y;
    T z;
    
    CUDA_HOST_DEVICE
    vec3(vec3& ref){
        x = ref.x;
        y = ref.y;
        z = ref.z;
    }

    CUDA_HOST_DEVICE
    vec3(): x(0), y(0), z(0){;}

    CUDA_HOST_DEVICE
    vec3(T a, T b, T c): x(a), y(b), z(c){;}

    CUDA_HOST_DEVICE
    vec3(const vec3& ref ): x(ref.x), y(ref.y), z(ref.z){;}

    CUDA_HOST_DEVICE
    vec3(const std::array<T,3>& ref ): x(ref[0]), y(ref[1]), z(ref[2]){;}

    CUDA_HOST_DEVICE
    vec3(const T* ref ): x(ref[0]), y(ref[1]), z(ref[2]){;}
    //#endif

    CUDA_HOST_DEVICE
    ~vec3(){;}

    CUDA_HOST_DEVICE
    #if defined(__CUDACC__)
    //sqrtf : for float, sqrtg: for double
    T norm()const{return sqrtf(x*x+y*y+z*z);}
    #else
    T norm()const{return std::sqrt(x*x+y*y+z*z);}
    #endif
    
    CUDA_HOST_DEVICE
    vec3<T>
    operator + 
    (const vec3<T>& r) const {
        return vec3<T>(
            x + r.x,
            y + r.y,
            z + r.z
        );
    }

    CUDA_HOST_DEVICE
    vec3<T>
    operator - 
    (const vec3<T>& r) const {
        return vec3<T>(
            x - r.x,
            y - r.y,
            z - r.z
        );
    }

    CUDA_HOST_DEVICE
    vec3<T> 
    operator * 
    (const T& r)const{
        return vec3<T>(
            x * r,
            y * r,
            z * r
        );
    }

    CUDA_HOST_DEVICE
    vec3<T>
    cross
    (const vec3<T>& r) const {
        return vec3<T>(
            y*r.z - z*r.y,
            z*r.x - x*r.z,
            x*r.y - y*r.x
        );
    }


    CUDA_HOST_DEVICE
    vec3<T>&
    operator= 
    (const vec3<T>& r){
        x = r.x ; y = r.y; z = r.z;
        return *this;
    }

    CUDA_HOST
    void dump() const {
        #if defined(__CUDACC__)
        /*
        printf("xx,xy,xz %f, %f, %f\n", xx,xy, xz);
        printf("yx,yy,yz %f, %f, %f\n", yx,yy, yz);
        printf("zx,zy,zz %f, %f, %f\n", zx,zy, zz);
        */
        #else
        std::cout<<"x,y,z: ("<< x <<", " << y <<", " << z <<") " << std::endl;
        #endif
    }
};


//this is a copy of HepRotation.
template<typename T> 
class vec4 {
public:
    //
    T x;
    T y;
    T z;
    T s; //scale
    
    CUDA_HOST_DEVICE
    vec4(vec4& ref){
        x = ref.x;
        y = ref.y;
        z = ref.z;
        s = ref.s;
    }

    CUDA_HOST_DEVICE
    vec4(): x(0), y(0), z(0), s(0){;}

    CUDA_HOST_DEVICE
    vec4(T a, T b, T c, T d): x(a), y(b), z(c), s(d){;}

    CUDA_HOST_DEVICE
    vec4(const vec4& ref ): x(ref.x), y(ref.y), z(ref.z), s(ref.s) {;}

    CUDA_HOST_DEVICE
    vec4(const T* ref ): x(ref[0]), y(ref[1]), z(ref[2]), s(ref[3]) {;}

    CUDA_HOST_DEVICE
    vec4(const std::array<T,4>& ref ): x(ref[0]), y(ref[1]), z(ref[2]), s(ref[3]) {;}
    //#endif

    CUDA_HOST_DEVICE
    ~vec4(){;}

    CUDA_HOST_DEVICE
    #if defined(__CUDACC__)
    //sqrtf : for float, sqrtg: for double
    T norm()const{return sqrtf(x*x+y*y+z*z+s*s);}
    #else
    T norm()const{return std::sqrt(x*x+y*y+z*z+s*s);}
    #endif
    
    CUDA_HOST_DEVICE
    vec4<T>
    operator + 
    (const vec4<T>& r) const {
        return vec4<T>(
            x + r.x,
            y + r.y,
            z + r.z,
            s + r.s
        );
    }

    CUDA_HOST_DEVICE
    vec4<T>
    operator - 
    (const vec4<T>& r) const {
        return vec4<T>(
            x - r.x,
            y - r.y,
            z - r.z,
            s - r.s
        );
    }

    CUDA_HOST_DEVICE
    vec4<T> 
    operator * 
    (const T& r)const{
        return vec4<T>(
            x * r,
            y * r,
            z * r,
            s * r
        );
    }

    CUDA_HOST
    void dump() const {
        #if defined(__CUDACC__)
        /*
        printf("xx,xy,xz %f, %f, %f\n", xx,xy, xz);
        printf("yx,yy,yz %f, %f, %f\n", yx,yy, yz);
        printf("zx,zy,zz %f, %f, %f\n", zx,zy, zz);
        */
        #else
        std::cout<<"x,y,z,s: ("<< x <<", " << y <<", " << z <<", " << s<<") " << std::endl;
        #endif
    }
};

}

#endif