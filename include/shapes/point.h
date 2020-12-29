//
// Created by nicol on 27/12/2020.
//

#ifndef TPA2020_SHAPEDISPLAY_POINT_H
#define TPA2020_SHAPEDISPLAY_POINT_H

namespace shapes{
    class Point {
    public:
        double x_, y_;
        Point() : x_(0.0), y_(0.0){};
        Point(double x, double y) : x_(x), y_(y){};
		//distruttore
	};
}

#endif //TPA2020_SHAPEDISPLAY_POINT_H
