#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

class Rectangle;
class GraphicsVisitor;

class Graphics {
public:
    virtual ~Graphics();
    virtual Rectangle getBoundingBox();
    virtual void add(Graphics *g);
    virtual void accept(GraphicsVisitor & av);
protected:
    Graphics();
};

#endif // GRAPHICS_H_INCLUDED
