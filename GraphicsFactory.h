#ifndef GRAPHICSFACTORY_H_INCLUDED
#define GRAPHICSFACTORY_H_INCLUDED
#include <string>
#include "Graphics.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class GraphicsFactory {
    public:
        Graphics * buildGraphicsFromFile(const char * fileName); /*implement the pseudo code */
        string fileContentsAsString(const char * fileName); /* implement line 1 of pseudo code */
        Graphics * extractGraphicsFromOneLine(std::string & contents, int & level); /*implement line 3 */
        void compose (); /* implement lines 5, 6 as well as line 9 */
    private:
        vector<string> obj;

    /////s
};


#endif // GRAPHICSFACTORY_H_INCLUDED
