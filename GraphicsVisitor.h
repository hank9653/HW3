#ifndef GRAPHICSVISITOR_H_INCLUDED
#define GRAPHICSVISITOR_H_INCLUDED

class SimpleGraphics;
class CompositeGraphics;

class GraphicsVisitor {
public:
    virtual ~GraphicsVisitor() {}
    virtual void visitSimpleGraphics(SimpleGraphics *sg)=0;
    virtual void visitCompositeGraphics(CompositeGraphics *cg)=0;
    virtual void enter() {}
    virtual void leave() {}
public:
    GraphicsVisitor(){}
};

#endif // GRAPHICSVISTIOR_H_INCLUDED
