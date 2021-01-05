#include <iostream>
#include "include/shapes/shape.h"
#include "include/shapes/display.h"
#include "include/shapes/point.h"

using namespace std;
using namespace shapes;

int main() {
    const int height = 60;
    const int width = 100;
    Display display(width, height);

    /*Square Q("Q", Point(1, 10), 5, height);
    Rectangle R("R", Point(3, 20), 6, 7, height);
    display.addShape(Q);
    display.addShape(R);*/
    int b1 = 10, h1 = 5;
    Triangle t1("T1", Point(50, 5), b1, h1, height, Point(50, 5));

    int b2 = 6, h2 = 12;
    Triangle t2("T2", Point(0, 0), b2, h2, height, Point(0, 0));

    display.addShape(t1);
    display.addShape(t2);

    //display.updateDisplay();
    display.totalArea();
    for (int i = 0; i < display.getNumbersOfShapeInTheDisplay(); ++i) {
        display.getShapes()[i]->printShape();
    }

    display.refresh(); // non stampa nulla BOH anche se è giutissimo
    return 0;
}
