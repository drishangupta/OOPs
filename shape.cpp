#include <iostream>
class Shape {

public:
    virtual int sides() const {
        return 0;
    }
    virtual double area() const{
        return 0;
    }
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    int l, b;

public:
    Rectangle(double a, double b) : l(a), b(b) {}

    int sides() const override {
        return 4;
    }
    double area() const override {
        return l * b;
    }
};

void display(const Shape *s) {
    std::cout << "No of Sides: " << s->sides() << '\n';
    std::cout << "Area: " << s->area() << '\n';
}

int main() {
    Rectangle r1(4, 5);
    display(&r1);
}