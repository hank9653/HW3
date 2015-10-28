#include "GraphicsFactory.h"

Graphics * GraphicsFactory::buildGraphicsFromFile(const char * fileName){
    ifstream file(fileName);
    string str;
    if(!file){
         throw string("file does not exist.");
    }else{
        while (std::getline(file, str))
        {
            obj.push_back(str);
        }
    }
    /*for (auto e:obj)
        cout<<e<<endl;*/
}/*implement the pseudo code */

string GraphicsFactory::fileContentsAsString(const char * fileName){
    ifstream file(fileName);
    string str;
    string output;
    if(!file){
         throw string("file does not exist.");
    }else{
        while (std::getline(file, str))
        {
            output+=str+"\n";
        }
    }
    return output;
}/* implement line 1 of pseudo code */

Graphics * GraphicsFactory::extractGraphicsFromOneLine(std::string & contents, int & level){

}/*implement line 3 */

void GraphicsFactory::compose(){

}/* implement lines 5, 6 as well as line 9 */

