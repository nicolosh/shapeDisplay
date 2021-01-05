//
// Created by nicol on 27/12/2020.
//

#ifndef TPA2020_SHAPEDISPLAY_DISPLAY_H
#define TPA2020_SHAPEDISPLAY_DISPLAY_H

#include <vector>
#include "shape.h"

//EXTRA: potrei far contare quante shape dello stesso tipo sono presenti nel display

namespace shapes {
    class Display {
    private:
        int height_, width_;
        std::vector<const Shape *> shapes_;
    public:
        Display(int width, int height) : width_(width), height_(height) {}

        int getHeight() const { return height_; }

        int getWidth() const { return width_; }

        void totalArea() const;

        const std::vector<const Shape *> &getShapes() const { return shapes_; }

        int getNumbersOfShapeInTheDisplay() const { return shapes_.size(); }

        void addShape(const Shape &shape); // aggiungo solo nella lista di shape del Display
        void removeShape(const Shape &shape); // rimuovo aggiungo solo nella lista di shape del Display
        void updateDisplay() const; // refresh display
        void refresh() const;
    };
}

#endif //TPA2020_SHAPEDISPLAY_DISPLAY_H
