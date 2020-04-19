#pragma once
#include "vec3f.h"
#include <iostream>

class Object {
    protected:
        Vec3f location;
        Color color;
    public:
        Object();
        Object(const Vec3f& v, const Color& c);
        Vec3f getlocation() const;
        Color getColor() const;
        virtual bool checkRay() const;
        virtual Vec3f getNormalVector(const Vec3f& v) const;
        friend std::istream& operator>>(std::istream& in, Object& obj);
};

class Sphere: public Object {
    private:
        double radius;
    public:
        Sphere();
        Sphere(const Vec3f& v, const Color& c, double r);
        bool checkRay() const;
        Vec3f getNormalVector(const Vec3f& v) const;
        friend std::istream& operator>>(std::istream& in, Sphere& sph);
};
