#include <iostream>
#include <cmath>
#include "Vector.h"

Vector2D::Vector2D() { 
    x_ = 0;
    y_ = 0;
}

Vector2D::Vector2D(double x, double y) {
    setXY(x, y);
}

void Vector2D::setX(double x) {
    x_ = x;
}

void Vector2D::setY(double y) {
    y_ = y;
}

void Vector2D::setXY(double x, double y) {
    x_ = x;
    y_ = y;
}

double Vector2D::getX() const {
    return x_;
}

double Vector2D::getY() const {
    return y_;
}

std::ostream &operator<<(std::ostream &out, Vector2D vector) {
    out << "(" << vector.getX() << ", " << vector.getY() << ")";
    return out;
}

std::istream &operator>>(std::istream &ins, Vector2D &vector) {
    std::cout << " Enter x: ";
    ins >> vector.x_;
    std::cout << "Enter y: ";
    ins >> vector.y_;
    return ins;
}

Vector2D Vector2D::operator+(const Vector2D &vector2D) const {
    return {x_ + vector2D.x_, y_ + vector2D.y_};
}

Vector2D Vector2D::operator-(const Vector2D &vector2D) const {
    return {x_ - vector2D.x_, y_ - vector2D.y_};
}

Vector2D Vector2D::operator*(const Vector2D &vector2D) const {
    return {x_ * vector2D.x_, y_ * vector2D.y_};
}

Vector2D Vector2D::operator/(const Vector2D &vector2D) const {
    return {x_ / vector2D.x_, y_ / vector2D.y_};
}


double Vector2D::lengthVector()const {
    return sqrt(x_ * x_ + y_ * y_);
}

double Vector2D::scalarMultiply(const Vector2D &vector, const Vector2D &vector2) {
    return ((vector.x_ * vector2.x_) + (vector.y_ * vector2.y_));
}


Vector2D Vector2D::multiplyToNumber(double num) const {
    return {num * x_, num * y_};
}





