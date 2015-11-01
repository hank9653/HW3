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
    cout<<dv.getDescription();
    CHECK(ans==dv.getDescription());
}

TEST(GraphicsFactory, fileContentsAsString) {
    GraphicsFactory g;
    //g.buildGraphicsFromFile("f1.txt");
    //g.fileContentsAsString("f1.txt");
    std::string ans("Comp R(-2,-2,3,4)\n");
    ans += std::string("  Comp R(-2,-2,3,3)\n");
    ans += std::string("    C(0,0,1)\n");
    ans += std::string("    S(-2,-2,2)\n");
    ans += std::string("  R(-1,-1,1,3)\n");
    CHECK(ans==g.fileContentsAsString("f1.txt"));
//    switch(string str)
}

TEST(GraphicsFactory, extractGraphicsFromOneLine) {
    GraphicsFactory g;
    CompositeGraphics c;
    DescriptionVisitor dv;

    int level=0;
    string shapeStr="C(0,0,1)";
    //g.buildGraphicsFromFile("f1.txt");
    //g.fileContentsAsString("f1.txt");
    c.add(g.extractGraphicsFromOneLine(shapeStr,level));

    level=0;
    shapeStr="S(-2,-2,2)";
    c.add(g.extractGraphicsFromOneLine(shapeStr,level));

    level=0;
    shapeStr="R(-1,-1,1,3)";
    c.add(g.extractGraphicsFromOneLine(shapeStr,level));
    c.accept(dv);
    std::string ans("Comp R(-2,-2,3,4)\n");
    ans += std::string("  C(0,0,1)\n");
    ans += std::string("  S(-2,-2,2)\n");
    ans += std::string("  R(-1,-1,1,3)\n");
    CHECK(ans==dv.getDescription());
//    switch(string str)
}

#endif // UTHW3_H_INCLUDED
