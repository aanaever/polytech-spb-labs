#ifndef TWODIMVECTOR_VECTOR_H
#define TWODIMVECTOR_VECTOR_H

class Vector2D {
private:
    double y_;
    double x_;
public:

    Vector2D();

    Vector2D(double x, double y);

    void setX(double x);

    void setY(double y);

    void setXY(double x, double y);

    double getX() const;

    double getY() const;

     friend std::ostream &operator<<(std::ostream &out, Vector2D vector);

    friend std::istream &operator>>(std::istream &ins, Vector2D &vector);


    Vector2D operator+(const Vector2D &other) const;

    Vector2D operator-(const Vector2D &other) const;

    Vector2D operator*(const Vector2D &other) const;

    Vector2D operator/(const Vector2D &other) const;

     double  lengthVector() const;

    static double scalarMultiply(const Vector2D &vector, const Vector2D &vector2);

    Vector2D multiplyToNumber(double num) const;
};


#endif //TWODIMVECTOR_VECTOR_H
