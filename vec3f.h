#pragma once
#include <cstdint>
#include <iostream>

class Vec3f {
    protected:
        float x[3];
    public:
        Vec3f();
        Vec3f(float in_x[3]);
        Vec3f(const Vec3f& v);
        Vec3f operator=(const Vec3f& v);
        float& operator[](size_t i);
        const float& operator[](size_t i) const;
        Vec3f operator+(const Vec3f& v) const;
        Vec3f operator-() const;
        Vec3f operator-(const Vec3f& v) const;
        float operator*(const Vec3f& v) const;
        Vec3f operator*(float a) const;
        float length();
        void normalize();
};

Vec3f operator*(float a, const Vec3f& v);
std::ostream& operator<<(std::ostream& out, const Vec3f& v);

class Color: public Vec3f {
    public:
        Color();
        Color(uint8_t in_x[3]);
        Color(const Vec3f& v);
        Color(const Color& c);
        void normalize();
};

std::ostream& operator<<(std::ostream& out, const Color& v);
