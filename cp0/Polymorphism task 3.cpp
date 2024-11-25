#include <iostream>
using namespace std;

class Point {
protected:
    int x, y;
public:
    Point(int xCoord = 0, int yCoord = 0) : x(xCoord), y(yCoord) {}

    virtual void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
};

class ColoredPoint : public Point {
private:
    string color;
public:
    ColoredPoint(int xCoord, int yCoord, const string& colorName) 
        : Point(xCoord, yCoord), color(colorName) {}

    void display() const override {
        cout << "ColoredPoint(" << x << ", " << y << ", Color: " << color << ")" << endl;
    }
};

int main() {
    Point p1(3, 4);
    Point p2(1, 2);

    Point p3 = p1 + p2;
    Point p4 = p1 - p2;

    p1.display();
    p2.display();
    p3.display();
    p4.display();

    ColoredPoint cp(5, 7, "Red");
    cp.display();

    ColoredPoint cp2(2, 3, "Blue");
    Point p5 = cp + cp2;
    p5.display();

    return 0;
}

