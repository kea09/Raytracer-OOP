#pragma once
#include "vec3f.h"
#include <iostream>
#include <vector>

class Object {
    protected:
        Vec3f location;
        Color color;
    public:
        Object();
        Object(const Vec3f& v, const Color& c);
        Vec3f getlocation() const;
        Color getColor() const;
        virtual std::vector<float> checkRay(const Vec3f& origin, const Vec3f& direction) const = 0;
        virtual Vec3f getNormalVector(const Vec3f& v) const = 0;
        friend std::istream& operator>>(std::istream& in, Object& obj);
        virtual ~Object() {}
};

class Sphere: public Object {
    private:
        double radius;
    public:
        Sphere();
        Sphere(const Vec3f& v, const Color& c, double r);
        virtual std::vector<float> checkRay(const Vec3f& origin, const Vec3f& direction) const;
        virtual Vec3f getNormalVector(const Vec3f& v) const;
        friend std::istream& operator>>(std::istream& in, Sphere& sph);
};
