#ifndef GRAPHICSFACTORY_H_INCLUDED
#define GRAPHICSFACTORY_H_INCLUDED
#include <string>
#include "Graphics.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

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
    private:
        vector<string> obj;
        stack<int> level;

    /////s
};


#endif // GRAPHICSFACTORY_H_INCLUDED
