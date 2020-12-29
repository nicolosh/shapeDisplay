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
        Display(int height, int width) : height_(height), width_(width) {}

        int getHeight() const { return height_; }

        int getWidth() const { return width_; }

        double totalArea() const;

        void addShape(const Shape &shape); // aggiungo solo nella lista di shape del Display
        void removeShape(const Shape &shape); // rimuovo aggiungo solo nella lista di shape del Display
        void updateDisplay() const; // refresh display
        void refresh() const;
    };
}

#endif //TPA2020_SHAPEDISPLAY_DISPLAY_H
