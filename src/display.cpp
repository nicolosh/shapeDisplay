//
// Created by nicol on 27/12/2020.
//

#include "../include/shapes/display.h"

void shapes::Display::totalArea() const {
    double sum = 0.0;
    for (int i = 0; i < shapes_.size(); ++i)
        if (shapes_[i] != nullptr)
            sum += shapes_[i]->area();

    std::cout << "Total area of shapes in display: " << sum << std::endl;
}

void shapes::Display::addShape(const shapes::Shape &shape) {
    //verifico che NON stia nel display come dimensioni o posizione
    if ((shape.area() > (width_ * height_)) || (shape.perimeter() > (width_ + height_) * 2) ||
        (shape.perimeter() <= 0) || (shape.area() <= 0) ||
        !((shape.getInitialPoint().x_ >= 0) && (shape.getInitialPoint().x_ <= width_)) ||
        !((shape.getInitialPoint().y_ >= 0) &&
          (shape.getInitialPoint().y_ <= height_))) // oppure se shape non è lista di tutte le possibili shape 2D
    {
        std::cout << "Cannot add this shape " << shape.getName() << std::endl;
        return;
    }

    //condizioni che non vanno bene
    for (int i = 1; i < shapes_.size(); ++i) {
        if (!shapes_[i - 1]->isPointInsideShape(shape.getInitialPoint())) {
            std::cout << "Cannot add your shape " << shape.getName() << std::endl;
            return;
        }
    }

    shapes_.push_back(&shape);
}

void shapes::Display::removeShape(const shapes::Shape &shape) {
    for (int i = 0; i < shapes_.size(); ++i) {
        if (
                (shapes_[i]->getName() == shape.getName()) &&
                (shapes_[i]->getInitialPoint().x_ == shape.getInitialPoint().x_) &&
                (shapes_[i]->getInitialPoint().y_ == shape.getInitialPoint().y_) &&
                (shapes_[i]->area() == shape.area()) &&
                (shapes_[i]->perimeter() == shape.perimeter())
                ) {
            shapes_[i] = nullptr;
            return;
        }
    }

    std::cout << "Cannot find requested shape" << std::endl;
}

void shapes::Display::updateDisplay() const {
    for (int i = 0; i < shapes_.size(); ++i) {
        if (shapes_[i] != nullptr)
            shapes_[i]->printShape();
    }
}

void shapes::Display::refresh() const {
    for (int i = height_; i >= 0; --i) {
        for (int j = 0; j < width_; ++j) {
            bool isFull = false;
            for (int k = 0; k < shapes_.size() && !isFull; ++k) {
                if (shapes_[i]->isPointInsideShape(Point(j, i))) {
                    isFull = true;
                }
            }
            if (isFull)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}
