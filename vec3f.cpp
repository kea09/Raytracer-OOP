#include "vec3f.h"
#include <cmath>
using std::size_t;

Vec3f::Vec3f() {
    for (size_t i = 0; i < 3; i++) {
        x[i] = 0;
    }
}

Vec3f::Vec3f(float in_x[3]) {
    for (size_t i = 0; i < 3; i++) {
        x[i] = in_x[i];
    }
}

Vec3f::Vec3f(const Vec3f& v) {
    for (size_t i = 0; i < 3; i++) {
        x[i] = v[i];
    }
}

Vec3f Vec3f::operator=(const Vec3f& v) {
    for (size_t i = 0; i < 3; i++) {
        x[i] = v[i];
    }
    return *this;
}

float& Vec3f::operator[](size_t i) {
    return x[i];
}

const float& Vec3f::operator[](size_t i) const {
    return x[i];
}

Vec3f Vec3f::operator+(const Vec3f& v) const {
    float coord[3];
    for (size_t i = 0; i < 3; i++) {
        coord[i] = x[i] + v[i];
    }
    return Vec3f(coord);
}

Vec3f Vec3f::operator-() const {
    float coord[3];
    for (size_t i = 0; i < 3; i++) {
        coord[i] = -x[i];
    }
    return Vec3f(coord);
}

Vec3f Vec3f::operator-(const Vec3f& v) const {
    return *this + (-v);
}

float Vec3f::operator*(const Vec3f& v) const {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += x[i] * v[i];
    }
    return sum;
}

Vec3f Vec3f::operator*(float a) const {
    float coord[3];
    for (size_t i = 0; i < 3; i++) {
        coord[i] = a * x[i];
    }
    return Vec3f(coord);
}

Vec3f operator*(float a, const Vec3f& v) {
    return v * a;
}

std::ostream& operator<<(std::ostream& out, const Vec3f& v) {
    for (size_t i = 0; i < 3; i++) {
        out << v[i] << ' ';
    }
    return out;
}

std::istream& operator>>(std::istream& in, Vec3f& v) {
    for (size_t i = 0; i < 3; i++) {
        in >> v[i];
    }
    return in;
}

float Vec3f::length() const {
    float sum = 0;
    for (size_t i = 0; i < 3; i++) {
        sum += x[i] * x[i];
    }
    return sqrt(sum);
}

void Vec3f::normalize() {
    float len = length();
    for (size_t i = 0; i < 3; i++) {
        x[i] /= len;
    }
}

Color::Color() : Vec3f() {}

Color::Color(uint8_t in_x[3]) {
    for (size_t i = 0; i < 3; i++) {
        x[i] = std::min(1.f, in_x[i] / 255.f);
    } 
}

Color::Color(const Vec3f& v) : Vec3f(v) {
    for (size_t i = 0; i < 3; i++) {
        x[i] = std::max(0.f, std::min(1.f, x[i] / 255.f));
    }
}

Color::Color(const Color& c) : Vec3f(c) {}

Color::Color(uint8_t c) {
    c = std::max(0.f, std::min(1.f, c / 255.f));
    for (size_t i = 0; i < 3; i++) {
        x[i] = c;
    } 
}

void Color::normalize() {
    for (size_t i = 0; i < 3; i++) {
        x[i] = std::max(0.f, std::min(1.f, x[i] / 255.f));
    }
}

std::ostream& operator<<(std::ostream& out, const Color& c) {
    for (size_t i = 0; i < 3; i++) {
        out << char(c[i] * 255);
    }
    return out;
}

std::istream& operator>>(std::istream& in, Color& c) {
    for (size_t i = 0; i < 3; i++) {
        in >> c[i];
        c[i] = std::max(0.f, std::min(1.f, c[i] / 255.f));
    }
    return in;
}

Color Color::operator*(float a) const {
    Color res = *this;
    for (size_t i = 0; i < 3; i++) {
        res[i] = std::max(0.f, std::min(1.f, res[i] * a));
    }
    return res;
}
