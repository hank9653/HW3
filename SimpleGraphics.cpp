#include "SimpleGraphics.h"
#include "Rectangle.h"
#include "AreaVisitor.h"

SimpleGraphics::SimpleGraphics (Shape *shape_inst):s(shape_inst) {}
Rectangle SimpleGraphics::getBoundingBox() {return s->getBoundingBox();}
void SimpleGraphics::accept(GraphicsVisitor &av) {av.visitSimpleGraphics(this);}
Shape * SimpleGraphics::shape() {return s;}
