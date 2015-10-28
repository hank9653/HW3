#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(int ll_x, int ll_y, int length, int width);
    int area();
    Rectangle getBoundingBox();
    int llx() const{return x;}
    int lly() const{return y;}
    int urx() const{return x+l;}
    int ury() const{return y+w;}
    std::string describe();
    //int perimeter();
private:
    int x, y;
    int l, w;

};


#endif // RECTANGLE_H_INCLUDED
