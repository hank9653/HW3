#ifndef DESCRIPTIONVISITOR_H_INCLUDED
#define DESCRIPTIONVISITOR_H_INCLUDED
#include "GraphicsVisitor.h"
#include "Graphics.h"

#include <string>

class DescriptionVisitor : public GraphicsVisitor {
public:
    DescriptionVisitor();
    std::string getDescription();
    void visitSimpleGraphics(SimpleGraphics *sg);
    void visitCompositeGraphics (CompositeGraphics *cg);
    void enter();
    void leave();
private:
    void pre();
    void post();
private:
    std::string desc;
    std::string indent;
};

#endif // DESCRIPTIONVISITOR_H_INCLUDED
