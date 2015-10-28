#include "AreaVisitor.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"

void AreaVisitor::visitSimpleGraphics(SimpleGraphics *sg) {
    a += sg->shape()->area();
}

void AreaVisitor::visitCompositeGraphics(CompositeGraphics *cg) {
    //area += cg->area();
}
