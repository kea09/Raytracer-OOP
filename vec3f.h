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
        float& operator[](std::size_t i);
        const float& operator[](std::size_t i) const;
        Vec3f operator+(const Vec3f& v) const;
        Vec3f operator-() const;
        Vec3f operator-(const Vec3f& v) const;
        virtual float operator*(const Vec3f& v) const;
        Vec3f operator*(float a) const;
        float length() const;
        void normalize();
};

Vec3f operator*(float a, const Vec3f& v);
std::ostream& operator<<(std::ostream& out, const Vec3f& v);
std::istream& operator>>(std::istream& in, Vec3f& v);

class Color: public Vec3f {
    public:
        Color();
        Color(uint8_t in_x[3]);
        Color(const Vec3f& v);
        Color(const Color& c);
        Color(uint8_t c);
        virtual Color operator*(float a) const;
        void normalize();
};

std::ostream& operator<<(std::ostream& out, const Color& c);
std::istream& operator>>(std::istream& in, Color& c);
