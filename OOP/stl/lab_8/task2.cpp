//2

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Shape {
public:
    Shape(double x, double y) : x(x), y(y) {}

    bool IsMoreLeft(const Shape& other) const {
        return x < other.x;
    }

    bool IsUpper(const Shape& other) const {
        return y > other.y;
    }

    virtual void Draw() const = 0;

protected:
    double x, y; 
};

class Circle : public Shape {
public:
    Circle(double x, double y, double radius) : Shape(x, y), radius(radius) {}

    void Draw() const override {
        cout << "Circle (" << x << ", " << y << "), radius = " << radius << endl;
    }

private:
    double radius; 
};


class Triangle : public Shape {
public:
    Triangle(double x, double y, double base, double height) : Shape(x, y), basis(base), height(height) {}

    void Draw() const override {
        cout << "Triangle (" << x << ", " << y << "), basis = " << basis << ", height = " << height << endl;
    }

private:
    double basis, height; 
};


class Square : public Shape {
public:
    Square(double x, double y, double side) : Shape(x, y), side(side) {}

    void Draw() const override {
        cout << "Square (" << x << ", " << y << "), side = " << side << endl;
    }
private:
    double side;
};

struct SortX {
    bool operator()(const Shape* shape1, const Shape* shape2) const {
        return shape1->IsMoreLeft(*shape2);
    }
};

struct SortTurnX {
    bool operator()(const Shape* shape1, const Shape* shape2) const {
        return shape2->IsMoreLeft(*shape1);
    }
};

struct SortY {
    bool operator()(const Shape* shape1, const Shape* shape2) const {
        return shape1->IsUpper(*shape2);
    }
};

struct SortTurnY {
    bool operator()(const Shape* shape1, const Shape* shape2) const {
        return shape2->IsUpper(*shape1);
    }
};


int main() {

    list<Shape*> shapes;

    shapes.push_back(new Circle(0.0, 0.0, 5.0));
    shapes.push_back(new Triangle(1.0, 2.0, 4.0, 3.0));
    shapes.push_back(new Square(-2.0, -1.0, 6.0));
    shapes.push_back(new Circle(3.0, 4.0, 2.0));
    shapes.push_back(new Triangle(-4.0, -3.0, 5.0, 6.0));
    shapes.push_back(new Square(2.0, -2.0, 4.0));

    cout << "Output of all shapes: "<< endl;
    for_each(shapes.begin(), shapes.end(), [](const Shape* shape) { shape->Draw(); });
    cout << endl;
    cout << endl;

    cout << "Sorting and output shapes by X (from left to rights): "<< endl;
    shapes.sort(SortX());
    for_each(shapes.begin(), shapes.end(), [](const Shape* shape) { shape->Draw(); });
    cout << endl;
    cout << endl;

    cout << "Sorting and output shapes by turn X (from right to left): "<< endl;
    shapes.sort(SortTurnX());
    for_each(shapes.begin(), shapes.end(), [](const Shape* shape) { shape->Draw(); });
    cout << endl;
    cout << endl;

    cout << "Sorting and output shapes by turn Y (top to bottom): "<< endl;
    shapes.sort(SortY());
    for_each(shapes.begin(), shapes.end(), [](const Shape* shape) { shape->Draw(); });
    cout << endl;
    cout << endl;

    cout << "Sorting and output shapes by turn Y (bottom to top): "<< endl;
    shapes.sort(SortTurnY());
    for_each(shapes.begin(), shapes.end(), [](const Shape* shape) { shape->Draw(); });
    cout << endl;
    cout << endl;

    return 0;
}
