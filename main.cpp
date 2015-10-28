#include "cppunitlite/TestHarness.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Graphics.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include "util.h"
#include <string>
#include <vector>
#include "AreaVisitor.h"
#include "DescriptionVisitor.h"
#include "utHW3.h"

int main(int argc, char** argv) {
	TestResult tr;
	TestRegistry::runAllTests(tr);

	return 0;
}


TEST(Shapes0915, first_success) {
    CHECK(true);
}

TEST(Circle, area) {
    Circle circle(0,0,1);
    LONGS_EQUAL(3,circle.area());
}

TEST(areaSum, Circle) {
    Circle c1(0,0,1), c2(0,0,2),c3(0,0,3);
    std::vector<Shape *> v;
    v.push_back(&c1);
    v.push_back(&c2);
    v.push_back(&c3);
    LONGS_EQUAL(42,areaSum(v));
}

TEST(areaSum, Square) {
    Square s1(0,0,1), s2(0,0,2),s3(0,0,3);
    std::vector<Shape *> v;
    v.push_back(&s1);
    v.push_back(&s2);
    v.push_back(&s3);
    LONGS_EQUAL(14,areaSum(v));
}

TEST(areaSum, Rectangle) {
    Rectangle r1(0,0,1,2), r2(0,0,2,3),r3(0,0,3,4);
    std::vector<Shape *> v;
    v.push_back(&r1);
    v.push_back(&r2);
    v.push_back(&r3);
    LONGS_EQUAL(20,areaSum(v));
}

TEST(areaSum, allShapes) {
    Circle c(0,0,1);
    Square s(0,0,2);
    Rectangle r(0,0,3,4);
    std::vector<Shape *> v;
    v.push_back(&c);
    v.push_back(&s);
    v.push_back(&r);
    LONGS_EQUAL(19,areaSum(v));
}

TEST(Shape, getBoundingBox) {
    Circle c(0,0,1);
    Rectangle r(1,1,1,2);
    Square s(0,0,3);

    // bounding box of a shape is a rectangle
    LONGS_EQUAL(-1,c.getBoundingBox().llx());
    LONGS_EQUAL(-1,c.getBoundingBox().lly());
    LONGS_EQUAL(1,c.getBoundingBox().urx());
    LONGS_EQUAL(1,c.getBoundingBox().ury());

    LONGS_EQUAL(1,r.getBoundingBox().llx());
    LONGS_EQUAL(1,r.getBoundingBox().lly());
    LONGS_EQUAL(2,r.getBoundingBox().urx());
    LONGS_EQUAL(3,r.getBoundingBox().ury());

    LONGS_EQUAL(0,s.getBoundingBox().llx());
    LONGS_EQUAL(0,s.getBoundingBox().lly());
    LONGS_EQUAL(3,s.getBoundingBox().urx());
    LONGS_EQUAL(3,s.getBoundingBox().ury());

    LONGS_EQUAL(4,c.getBoundingBox().area());
    LONGS_EQUAL(2,r.getBoundingBox().area());
    LONGS_EQUAL(9,s.getBoundingBox().area());
}

TEST (CompositeGraphics, defaultBoundingBox) {
    CompositeGraphics g;
    // CompositeGraphics object has a default bounding box of
    // rectangle (0,0,0,0)
    LONGS_EQUAL(0,g.getBoundingBox().llx());
    LONGS_EQUAL(0,g.getBoundingBox().lly());
    LONGS_EQUAL(0,g.getBoundingBox().urx());
    LONGS_EQUAL(0,g.getBoundingBox().ury());
    LONGS_EQUAL(0,g.getBoundingBox().area());
}

TEST(SimpleGraphics, ctor_BoundingBox) {
    // SimpleGraphics object points to a Shape object
    Graphics *g1 = new SimpleGraphics(new Circle(0,0,1));
    Graphics *g2 = new SimpleGraphics(new Square(0,0,2));
    Graphics *g3 = new SimpleGraphics(new Rectangle(5,6,3,4));

    LONGS_EQUAL(-1,g1->getBoundingBox().llx());
    LONGS_EQUAL(-1,g1->getBoundingBox().lly());
    LONGS_EQUAL(1,g1->getBoundingBox().urx());
    LONGS_EQUAL(1,g1->getBoundingBox().ury());

    LONGS_EQUAL(0,g2->getBoundingBox().llx());
    LONGS_EQUAL(0,g2->getBoundingBox().lly());
    LONGS_EQUAL(2,g2->getBoundingBox().urx());
    LONGS_EQUAL(2,g2->getBoundingBox().ury());

    LONGS_EQUAL(5,g3->getBoundingBox().llx());
    LONGS_EQUAL(6,g3->getBoundingBox().lly());
    LONGS_EQUAL(8,g3->getBoundingBox().urx());
    LONGS_EQUAL(10,g3->getBoundingBox().ury());

}

TEST(SimpleGraphics, AddingGraphicsObjectShouldThrowException) {
    SimpleGraphics g(new Circle(0,0,1));
    // adding Graphics throws an exception
    try {
        g.add(new SimpleGraphics(new Circle(0,0,0)));
    } catch (std::string s) {
        CHECK(std::string("Cannot add child")==s);
    }
    // adding SimpleGraphics throws an exception
    try {
        g.add(new SimpleGraphics(new Circle(0,0,1)));
    } catch (std::string s) {
        CHECK(std::string("Cannot add child")==s);
    }

    // adding CompositeGraphics throws an exception
    try {
        g.add(new CompositeGraphics);
    } catch (std::string s) {
        CHECK(std::string("Cannot add child")==s);
    }
}

TEST(CompositeGraphics, addingOneChild) {
    CompositeGraphics g;

    try {
        g.add(new SimpleGraphics(new Circle(0,0,2)));
    } catch (std::string s) {
        FAIL("Should not throw exception");
    }

    LONGS_EQUAL(16,g.getBoundingBox().area());
}

TEST(CompositeGraphics, addingTwoChildrenAndGetBoundingBox) {
    CompositeGraphics g;

    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    LONGS_EQUAL(-2,g.getBoundingBox().llx());
    LONGS_EQUAL(-2,g.getBoundingBox().lly());
    LONGS_EQUAL(1,g.getBoundingBox().urx());
    LONGS_EQUAL(1,g.getBoundingBox().ury());
}

TEST(CompositeGraphics, SimpleAndCompositeChildrenAndGetBoundingBox) {
    CompositeGraphics g;
    SimpleGraphics r(new Rectangle (-1,-1,1,3));

    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));
    CompositeGraphics h;
    h.add(&g);
    h.add(&r);

    LONGS_EQUAL(-2,h.getBoundingBox().llx());
    LONGS_EQUAL(-2,h.getBoundingBox().lly());
    LONGS_EQUAL(1,h.getBoundingBox().urx());
    LONGS_EQUAL(2,h.getBoundingBox().ury());

}

TEST (AreaVisitor, Simple) {
    SimpleGraphics s(new Rectangle(0,0,2,3));
    AreaVisitor av;
    s.accept(av);

    LONGS_EQUAL(6,av.area());
}

TEST (AreaVisitor, Composite) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    AreaVisitor av;
    g.accept(av);

    LONGS_EQUAL(7,av.area());

    SimpleGraphics r(new Rectangle (-1,-1,1,3));

    CompositeGraphics h;
    h.add(&g);
    h.add(&r);

    AreaVisitor av2;
    h.accept(av2);

    LONGS_EQUAL(10,av2.area());
}

TEST(AreaVisitor, derivedFromGraphicsVisitor) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));
    SimpleGraphics r(new Rectangle (-1,-1,1,3));
    CompositeGraphics h;

    h.add(&g);
    h.add(&r);

    GraphicsVisitor * av = new AreaVisitor;
    h.accept(*av);

    LONGS_EQUAL(10, static_cast<AreaVisitor *>(av)->area());
}

TEST (Shape, descriptions) {
    Shape * c = new Circle(0,0,1);
    CHECK(std::string("C(0,0,1)")== c->describe());
    c = new Square(0,0,1);
    CHECK(std::string("S(0,0,1)")== c->describe());
    c = new Rectangle(0,0,1,2);
    CHECK(std::string("R(0,0,1,2)")== c->describe());
}

TEST (DescVisitor, SimpleGraphics) {
    SimpleGraphics s(new Rectangle(0,0,2,3));
    DescriptionVisitor dv;
    s.accept(dv);

    CHECK(std::string("R(0,0,2,3)\n")==dv.getDescription());
}

TEST (DescVisitor, CompositeGraphics) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    DescriptionVisitor dv;
    g.accept(dv);

    std::string ans("Comp R(-2,-2,3,3)\n");
    ans += std::string("  C(0,0,1)\n");
    ans += std::string("  S(-2,-2,2)\n");
    CHECK(ans==dv.getDescription());
    //std::cout << dv.getDescription() << std::endl;
}

TEST (DescVisitor, CompositeGraphicsWithComposite) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    SimpleGraphics r(new Rectangle (-1,-1,1,3));

    CompositeGraphics h;
    h.add(&g);
    h.add(&r);

    DescriptionVisitor dv;
    h.accept(dv);

    std::string ans("Comp R(-2,-2,3,4)\n");
    ans += std::string("  Comp R(-2,-2,3,3)\n");
    ans += std::string("    C(0,0,1)\n");
    ans += std::string("    S(-2,-2,2)\n");
    ans += std::string("  R(-1,-1,1,3)\n");
    CHECK(ans==dv.getDescription());
    //std::cout << dv.getDescription() << std::endl;
}


