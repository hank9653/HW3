#ifndef GRAPHICSFACTORY_H_INCLUDED
#define GRAPHICSFACTORY_H_INCLUDED
#include <string>
#include "Graphics.h"
#include "CompositeGraphics.h"
#include "SimpleGraphics.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <stdio.h>
#include<sstream>
#include "DescriptionVisitor.h"

using namespace std;

class GraphicsFactory {
    public:
        Graphics * buildGraphicsFromFile(const char * fileName); /*implement the pseudo code */
        string fileContentsAsString(const char * fileName); /* implement line 1 of pseudo code */
        Graphics * extractGraphicsFromOneLine(std::string & contents, int & level); /*implement line 3 */
        void compose (); /* implement lines 5, 6 as well as line 9 */
        int currentlevel(string str);
        int previouslevel();
        string removeTrim(string str);
        void printComposite(stack<string> obj,stack<int> level);
        int stringToInt(string str);
    private:
        //<string> obj;
        stack<Graphics*> obj;
        stack<Graphics*> compositeObj;
        stack<int> level;
        stack<int> prelevel;
        bool sublevel=true;

    /////s
};


#endif // GRAPHICSFACTORY_H_INCLUDED
