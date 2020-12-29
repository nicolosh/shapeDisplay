//
// Created by nicol on 27/12/2020.
//

#ifndef TPA2020_SHAPEDISPLAY_SHAPE_H
#define TPA2020_SHAPEDISPLAY_SHAPE_H

#include <string>
#include <vector>
#include <iostream>
#include "point.h"
#include <math.h>

//Versione con le matrici (idea marta)........

//potrei tenermi dei riferimenti ai punti già stampati/occupati del display e controllare così
//di non inserire shape sovrapponendole tra loro

//la mia versione stamperà una figura per display



namespace shapes {
    class Shape {
    protected:
        std::string name_;
        const Point initialPoint_;
        double area_, perimeter_;
        int heightDisplay_, widthDisplay_;
    public:
        Shape(const std::string &name, const Point &initialPoint, int widthDisplay, int heightDisplay);

        virtual double area() const = 0;

        virtual double perimeter() const = 0;

        virtual void printShape() const = 0;

        virtual bool isPointInsideShape(const Point &p) const = 0;

        const Point &getInitialPoint() const { return initialPoint_; }

        const std::string &getName() const { return name_; }

    };

    class Triangle : public Shape {
    protected:
        int base_, height_;
        const Point v1_, v2_, v3_;

        double sign(const Point &p1, const Point &p2, const Point &p3) const;

    public:
        Triangle(const std::string &name, const Point &initialPoint, int base, int height,
                 int widthDisplay, int heightDisplay, const Point &v1, const Point &v2,
                 const Point &v3);

        double area() const override;

        double perimeter() const override;

        void printShape() const override;

        bool isPointInsideShape(const Point &p) const override;
    };

    class Circle : public Shape {
    protected:
        int radius_;
    public:
        Circle(const std::string &name, const Point &initialPoint, int radius, int widthDisplay, int heightDisplay);

        double area() const override;

        double perimeter() const override;

        void printShape() const override;

        bool isPointInsideShape(const Point &p) const override;
    };

    class Rectangle : public Shape {
    protected:
        int height_, base_;
    public:
        Rectangle(const std::string &name, const Point &initialPoint, int base, int height, int widthDisplay,
                  int heightDisplay);

        double area() const override;

        double perimeter() const override;

        void printShape() const override;

        bool isPointInsideShape(const Point &p) const override;
    };

    class Ellipse : public Shape {
    protected:
        int semiAxisX_, semiAxisY_;
    public:
        Ellipse(const std::string &name, const Point &initialPoint, int semiAxisX, int semiAxisY, int widthDisplay,
                       int heightDisplay);

        double area() const override;

        double perimeter() const override;

        void printShape() const override;

        bool isPointInsideShape(const Point &p) const override;
    };

    class Rhombus : public Shape {
    protected:
        int D_, d_;
    public:
        Rhombus(const std::string &name, const Point &initialPoint, int D, int d, int widthDisplay, int heightDisplay);

        double area() const override;

        double perimeter() const override;

        void printShape() const override;

        bool isPointInsideShape(const Point &p) const override;
    };

    class Trapeze : public Shape {
    protected:
        int baseMajor_, baseMinor_, height_;
    public:
        Trapeze(const std::string &name, const Point &initialPointt, int baseMajor, int baseMinor, int height,
                int widthDisplay, int heightDisplay);

        double area() const override;

        double perimeter() const override;

        void printShape() const override;

        bool isPointInsideShape(const Point &p) const override;
    };

    class Parallelogram : public Shape {
    protected:
        int base_, height_;
    public:
        Parallelogram(const std::string &name, const Point &initialPoint, int base, int height, int widthDisplay,
                      int heightDisplay);

        double area() const override;

        double perimeter() const override;

        void printShape() const override;

        bool isPointInsideShape(const Point &p) const override;
    };

    class Square : public Shape {
    protected:
        int side_;
    public:
        Square(const std::string &name, const Point &initialPoint, int side, int widthDisplay, int heightDisplay);

        double area() const override;

        double perimeter() const override;

        void printShape() const override;

        bool isPointInsideShape(const Point &p) const override;
    };

    //estendibile alle altre figure geometriche 2D


}
#endif //TPA2020_SHAPEDISPLAY_SHAPE_H
