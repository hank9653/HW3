#ifndef UTHW3_H_INCLUDED
#define UTHW3_H_INCLUDED
#include "cppunitlite/TestHarness.h"
#include "GraphicsFactory.h"
#include "DescriptionVisitor.h"


TEST(utHW3, first_success) {
    CHECK(true);
}

TEST(GraphicsFactory, buildGraphicsFromFile) {
    GraphicsFactory g;

    DescriptionVisitor dv;

    std::string ans("Comp R(-2,-2,3,4)\n");
    ans += std::string("  Comp R(-2,-2,3,3)\n");
    ans += std::string("    C(0,0,1)\n");
    ans += std::string("    S(-2,-2,2)\n");
    ans += std::string("  R(-1,-1,1,3)\n");

    try {
        g.buildGraphicsFromFile("f1.txt")->accept(dv);
        //FAIL("exception not thrown");
    } catch (std::string st) {
        CHECK(std::string("file does not exist.")==st);
    }

    CHECK(ans==dv.getDescription());
    //cout<<dv.getDescription();
}

TEST(GraphicsFactory, fileContentsAsString) {
    GraphicsFactory g;


    std::string ans("Comp R(-2,-2,3,4)\n");
    ans += std::string("  Comp R(-2,-2,3,3)\n");
    ans += std::string("    C(0,0,1)\n");
    ans += std::string("    S(-2,-2,2)\n");
    ans += std::string("  R(-1,-1,1,3)\n");
    CHECK(ans==g.fileContentsAsString("f1.txt"));

}

TEST(GraphicsFactory, extractGraphicsFromOneLine) {
    GraphicsFactory g;
    CompositeGraphics c1;
    DescriptionVisitor dv;
    int level;
    string shapeStr;


    level=0;
    shapeStr="C(0,0,1)";
    Graphics *z=g.extractGraphicsFromOneLine(shapeStr,level);
    //c1.add(z);
DescriptionVisitor SV;

    z->accept(SV);
    cout<<SV.getDescription();
    CHECK(shapeStr+"\n"==SV.getDescription());


    level=0;
    shapeStr="S(-2,-2,2)";
    c1.add(g.extractGraphicsFromOneLine(shapeStr,level));


    CompositeGraphics c2;
    c2.add(&c1);

    level=1;
    shapeStr="  R(-1,-1,1,3)";
    c2.add(g.extractGraphicsFromOneLine(shapeStr,level));
    c2.accept(dv);

    std::string ans("Comp R(-2,-2,3,4)\n");
    ans += std::string("  Comp R(-2,-2,3,3)\n");
    ans += std::string("    C(0,0,1)\n");
    ans += std::string("    S(-2,-2,2)\n");
    ans += std::string("  R(-1,-1,1,3)\n");

    //cout << dv.getDescription() << endl;
    //CHECK(ans==dv.getDescription());
}

#endif // UTHW3_H_INCLUDED
