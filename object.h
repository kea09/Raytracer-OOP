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
        virtual void checkRay(const Vec3f& origin, const Vec3f& direction, float& t1, float& t2) const = 0;
        virtual Vec3f getNormalVector(const Vec3f& v) const = 0;
        friend std::istream& operator>>(std::istream& in, Object& obj);
        virtual ~Object() {}
};

class Sphere: public Object {
    private:
        float radius;
    public:
        Sphere();
        Sphere(const Vec3f& v, const Color& c, float r);
        virtual void checkRay(const Vec3f& origin, const Vec3f& direction, float& t1, float& t2) const;
        virtual Vec3f getNormalVector(const Vec3f& v) const;
        friend std::istream& operator>>(std::istream& in, Sphere& sph);
};
