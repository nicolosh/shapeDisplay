//
// Created by nicol on 27/12/2020.
//

#include "../include/shapes/shape.h"

shapes::Shape::Shape(const std::string &name, const Point &initialPoint, int widthDisplay,
                     int heightDisplay) : name_(name), initialPoint_(initialPoint), widthDisplay_(widthDisplay),
                                          heightDisplay_(heightDisplay) {}

//TRIANGLE

bool shapes::Triangle::isPointInsideShape(const Point &p) const {
    double d1 = sign(p, v1_, v2_);
    double d2 = sign(p, v2_, v3_);
    double d3 = sign(p, v3_, v1_);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

double shapes::Triangle::sign(const Point &p1, const Point &p2, const Point &p3) const {
    return (p1.x_ - p3.x_) * (p2.y_ - p3.y_) - (p2.x_ - p3.x_) * (p1.y_ - p3.y_);
}

shapes::Triangle::Triangle(const std::string &name, const Point &initialPoint, int base, int height, int widthDisplay,
                           int heightDisplay, const Point &v1, const Point &v2,
                           const Point &v3) :
        Shape(name, initialPoint, widthDisplay, heightDisplay), base_(base), height_(height), v1_(v1), v2_(v2),
        v3_(v3) {}

double shapes::Triangle::area() const {
    return double(base_ * height_ / 2);
}

void shapes::Triangle::printShape() const {
    int base = (base_ % 2 == 0 ? base_ + 1 : base_);

    int levels = base / 2;
    int heightEachLevel = height_ / levels;

    for (int i = 0; i < heightDisplay_ - height_ - initialPoint_.y_; ++i)
        std::cout << /*heightDisplay_ - i <<*/ std::endl;

    int asteriskEachLevel = 1;
    int spacesEachLevel = initialPoint_.x_ + base / 2;
    for (int i = 1; i <= levels; ++i) {
        for (int j = 1; j <= heightEachLevel; ++j) {
            for (int k = 1; k <= spacesEachLevel; ++k) {
                std::cout << " ";
            }
            for (int k = 1; k <= asteriskEachLevel; ++k) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        spacesEachLevel--;
        asteriskEachLevel += 2;
    }

    // stampo base del triangolo
    for (int i = 0; i < initialPoint_.x_; ++i)
        std::cout << " ";
    for (int j = 0; j < base; ++j) {
        std::cout << "*";
    }

    std::cout << std::endl;
    for (int i = heightDisplay_ - initialPoint_.y_ + 1; i < heightDisplay_; ++i)
        std::cout << /*heightDisplay_ - i <<*/ std::endl;

    if (initialPoint_.y_ > 0)
        std::cout << 0 << std::endl;
}


//deve essere per forza isoscele per stamparlo
double shapes::Triangle::perimeter() const {
    return double(base_ + 2 * sqrt(pow(base_ / 2, 2) + pow(height_, 2)));
}


//RECTANGLE

shapes::Rectangle::Rectangle(const std::string &name, const Point &initialPoint, int base, int height, int widthDisplay,
                             int heightDisplay) :
        Shape(name, initialPoint, height, widthDisplay), base_(base), height_(height) {}

double shapes::Rectangle::area() const {
    return double(base_ * height_);
}

double shapes::Rectangle::perimeter() const {
    return double(2 * (base_ + height_));
}

void shapes::Rectangle::printShape() const {

    for (int i = 0; i < heightDisplay_ - height_ - initialPoint_.y_; ++i)
        std::cout << /*heightDisplay_ - i <<*/ std::endl;


    for (int rows = 0; rows <= height_; ++rows) {

        for (int i = 0; i < initialPoint_.x_; ++i) {
            std::cout << " ";
        }
        for (int cols = 0; cols < base_; ++cols) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = heightDisplay_ - initialPoint_.y_ + 1; i < heightDisplay_; ++i)
        std::cout << /*heightDisplay_ - i <<*/ std::endl;

    if (initialPoint_.y_ > 0)
        std::cout << 0 << std::endl; // origine del mio srf
}

bool shapes::Rectangle::isPointInsideShape(const shapes::Point &p) const {
    return false; // implementare
}

//ELLIPSE

shapes::Ellipse::Ellipse(const std::string &name, const Point &initialPoint, int semiAxisX, int semiAxisY,
                         int widthDisplay,
                         int heightDisplay) :
        Shape(name, initialPoint, widthDisplay, heightDisplay), semiAxisX_(semiAxisX), semiAxisY_(semiAxisY) {}

double shapes::Ellipse::area() const {
    return (M_PI * semiAxisX_ * semiAxisY_);
}

double shapes::Ellipse::perimeter() const {
    return 0.0; // implementare (diverse formule su web)
}

void shapes::Ellipse::printShape() const {

    //.........difficile da stampare
    return;
}

bool shapes::Ellipse::isPointInsideShape(const shapes::Point &p) const {
    return false;//fare
}

//RHOMBUS

shapes::Rhombus::Rhombus(const std::string &name, const Point &initialPoint, int D, int d, int widthDisplay,
                         int heightDisplay) :
        Shape(name, initialPoint, widthDisplay, heightDisplay), D_(D), d_(d) {}


double shapes::Rhombus::area() const {
    return double(D_ * d_ / 2);
}

double shapes::Rhombus::perimeter() const {
    return double(4 * sqrt(pow(D_ / 2, 2) + pow(d_ / 2, 2)));
}


void shapes::Rhombus::printShape() const {
    return;
    // ........... da fare!
}

bool shapes::Rhombus::isPointInsideShape(const shapes::Point &p) const {
    return false;//fare
}


//CIRCLE

shapes::Circle::Circle(const std::string &name, const Point &initialPoint, int radius, int widthDisplay,
                       int heightDisplay) :
        Shape(name, initialPoint, widthDisplay, heightDisplay), radius_(radius) {}

double shapes::Circle::area() const {
    return (M_PI * radius_ * radius_);
}

double shapes::Circle::perimeter() const {
    return (2 * M_PI * radius_);
}

void shapes::Circle::printShape() const {
    //.......... da fare
    return;
}

bool shapes::Circle::isPointInsideShape(const shapes::Point &p) const {
    double scarto = abs(sqrt(pow(initialPoint_.x_ - p.x_, 2) + pow(initialPoint_.y_ - p.y_, 2)));
    if (scarto < radius_)
        return true;

    return false;
}


//TRAPEZE

shapes::Trapeze::Trapeze(const std::string &name, const Point &initialPoint, int baseMajor, int baseMinor, int height,
                         int widthDisplay,
                         int heightDisplay) :
        Shape(name, initialPoint, widthDisplay,
              heightDisplay), baseMajor_(baseMajor), baseMinor_(baseMinor), height_(height) {}


double shapes::Trapeze::area() const {
    return double((baseMajor_ + baseMinor_) * height_ / 2);
}

double shapes::Trapeze::perimeter() const {
    return double(baseMajor_ + baseMinor_ + 2 * sqrt(pow(height_, 2) + pow((baseMajor_ - baseMinor_) / 2, 2)));
}

void shapes::Trapeze::printShape() const {
    //difficile
    return;
}

bool shapes::Trapeze::isPointInsideShape(const shapes::Point &p) const {
    return false;// fare
}


//PARALLELOGRAM

shapes::Parallelogram::Parallelogram(const std::string &name, const Point &initialPoint, int base, int height,
                                     int widthDisplay,
                                     int heightDisplay) :
        Shape(name, initialPoint, widthDisplay,
              heightDisplay), base_(base), height_(height) {}

double shapes::Parallelogram::area() const {
    return double(base_ * height_);
}

double shapes::Parallelogram::perimeter() const {
    return double(2 * (base_ + height_));
}

void shapes::Parallelogram::printShape() const {
    //........... da fare
    return;

}

bool shapes::Parallelogram::isPointInsideShape(const shapes::Point &p) const {
    return false; // da fare
}

//SQUARE

shapes::Square::Square(const std::string &name, const Point &initialPoint, int side, int widthDisplay,
                       int heightDisplay) :
        Shape(name, initialPoint, widthDisplay,
              heightDisplay), side_(side) {}

double shapes::Square::area() const {
    return double(side_ * side_);
}

double shapes::Square::perimeter() const {
    return double(side_ * 4);
}

void shapes::Square::printShape() const {
    for (int i = 0; i < heightDisplay_ - side_ - initialPoint_.y_; ++i)
        std::cout << /*heightDisplay_ - i <<*/ std::endl;


    for (int rows = 0; rows <= side_; ++rows) {
        for (int i = 0; i < initialPoint_.x_; ++i) {
            std::cout << " ";
        }
        for (int cols = 0; cols < side_; ++cols) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for (int i = heightDisplay_ - initialPoint_.y_ + 1; i < heightDisplay_; ++i)
        std::cout << /*heightDisplay_ - i <<*/ std::endl;

    if (initialPoint_.y_ > 0)
        std::cout << 0 << std::endl; // origine del mio srf
}

bool shapes::Square::isPointInsideShape(const shapes::Point &p) const {
    return false; // da fare
}

// OTHERS SHAPES.......(2D)

