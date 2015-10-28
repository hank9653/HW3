#ifndef UTHW3_H_INCLUDED
#define UTHW3_H_INCLUDED
#include "cppunitlite/TestHarness.h"
#include "GraphicsFactory.h"


TEST(utHW3, first_success) {
    CHECK(true);
}

TEST(GraphicsFactory, buildGraphicsFromFile) {
    GraphicsFactory g;
    try {
        g.buildGraphicsFromFile("f1.txt");
        //FAIL("exception not thrown");
    } catch (string st) {
        CHECK(string("file does not exist.")==st);
    }

    //CHECK(a correctly constructed CompositeGraphics);
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
}


#endif // UTHW3_H_INCLUDED
