#ifndef AREAVISITOR_H_INCLUDED
#define AREAVISITOR_H_INCLUDED

#include "GraphicsVisitor.h"

class AreaVisitor : public GraphicsVisitor{
public:
    AreaVisitor():a(0){}
    int area() {return a;}
    void visitSimpleGraphics(SimpleGraphics *sg);
    void visitCompositeGraphics (CompositeGraphics *cg);
private:
    int a;
};

#endif // AREAVISITOR_H_INCLUDED
