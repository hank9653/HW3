#include "GraphicsFactory.h"

Graphics * GraphicsFactory::buildGraphicsFromFile(const char * fileName){
    ifstream file(fileName);
    string str;
    if(!file){
         throw string("file does not exist.");
    }else{
        stack<string> obj;
        string tmp;
        while (std::getline(file, str))
        {
            int curlevel=currentlevel(str);
            if (curlevel<previouslevel()){
                string simpleGraphics;
                simpleGraphics="]"+simpleGraphics;
                while(previouslevel()>curlevel){
                    simpleGraphics=obj.top()+simpleGraphics;
                    level.pop();
                    obj.pop();
                    if(previouslevel()!=curlevel){
                        simpleGraphics=","+simpleGraphics;
                    }
                    //compose();compose into a CompositeGraphics object
                }
                simpleGraphics="["+simpleGraphics;
                obj.top()+=removeTrim(simpleGraphics);
                //cout<<level.top()<<" "<<obj.top()<<endl;
                printComposite(obj,level);
            }
            obj.push(removeTrim(str));
            level.push(curlevel);
            //cout<<level.top()<<" "<<obj.top()<<endl;
            printComposite(obj,level);
        }

        int curlevel=level.top();
        string simpleGraphics;
        simpleGraphics="]"+simpleGraphics;
        while(level.size()>1){
            simpleGraphics=obj.top()+simpleGraphics;
            level.pop();
            obj.pop();
            if(previouslevel()!=0){
                simpleGraphics=","+simpleGraphics;
            }
        }
        simpleGraphics="["+simpleGraphics;
        obj.top()+=removeTrim(simpleGraphics);
        //cout<<level.top()<<" "<<obj.top()<<endl;
        printComposite(obj,level);
    }
}/*implement the pseudo code */

string GraphicsFactory::fileContentsAsString(const char * fileName){
    ifstream file(fileName);
    string str;
    string output;
    if(!file){
         return string("file does not exist.");
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


int GraphicsFactory::currentlevel(string str){
    int currentlevel=0;
    for(int i=0;i<str.size();i++){
        if(str[i]!=' '){
            currentlevel/=2;
            break;
        }
        currentlevel++;
    }
    return currentlevel;
}
int GraphicsFactory::previouslevel(){
    int previouslevel=0;
    if(!level.empty()){
        previouslevel=level.top();
    }
    return previouslevel;
}

string GraphicsFactory::removeTrim(string str){
    string tmp;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!=' ')
        {
            tmp+=str[i];
        }
    }
    return tmp;
}

void GraphicsFactory::printComposite(stack<string> obj,stack<int> level)
{
    while (!obj.empty())
    {
        cout<<level.top()<<","<< obj.top()<<endl;
        obj.pop();
        level.pop();
    }

    cout<<endl<<endl;
}


