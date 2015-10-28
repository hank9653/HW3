#include "DescriptionVisitor.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include "Rectangle.h"

DescriptionVisitor::DescriptionVisitor():desc(std::string("")), indent(std::string("")){}
std::string DescriptionVisitor::getDescription() {return desc;}
void DescriptionVisitor::visitSimpleGraphics(SimpleGraphics *sg) {
    pre();
    desc += sg->shape()->describe();
    post();
}
void DescriptionVisitor::visitCompositeGraphics (CompositeGraphics *cg) {
    pre();
    desc += std::string("Comp ");
    desc += cg->getBoundingBox().describe();
    post();
}
void DescriptionVisitor::pre() {desc += indent;}
void DescriptionVisitor::post() {desc += std::string("\n");}
void DescriptionVisitor::enter() {indent += std::string("  ");}
void DescriptionVisitor::leave() {indent = indent.substr(0,indent.size()-2);}
