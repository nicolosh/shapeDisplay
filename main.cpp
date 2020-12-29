#include <iostream>
#include "include/shapes/shape.h"
#include "include/shapes/display.h"
#include "include/shapes/point.h"

using namespace std;
using namespace shapes;

int main() {
    const int height = 40;
    const int width = 70;
    Display display(width, height);

    Square Q("Q", Point(1, 10), 5, width, height);
    Rectangle R("R", Point(3, 20), 6, 7, width, height);
    display.addShape(Q);
    display.addShape(R);
    int b1 = 10, h1 = 5;
    //Triangle t1("T1", Point(50,5), b1, h1);

    int b2 = 6, h2 = 12;
    //Triangle t2("T2", Point(0,0), b2, h2);

    //display.addShape(t1);
    //display.addShape(t2);

    display.updateDisplay();
    double areaTot = display.totalArea();
    cout << areaTot;
    //display.refresh();
    return 0;
}
