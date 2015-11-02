#include "GraphicsFactory.h"

Graphics * GraphicsFactory::buildGraphicsFromFile(const char * fileName){
    ifstream file(fileName);
    string str;
    if(!file){
        throw string("file does not exist.");
    }else{
        while (std::getline(file, str))
        {
            int curlevel=currentlevel(str);
            level.push(curlevel);
            if (curlevel<previouslevel()){
                while(previouslevel()>curlevel){
                    compositeObj.push(obj.top());
                    level.pop();
                    obj.pop();
                }
                level.top()=curlevel;
                sublevel=false;
                compose();//compose into a CoobjmpositeGraphics object
            }
            obj.push(extractGraphicsFromOneLine(str,curlevel));
        }
        sublevel=true;
        compose();
        return obj.top();
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
    string str;
    string value;
    int data[4];
    bool start=false;
    for(int i=(level)*2;i<contents.size();i++){
        if(contents[i]=='(')
        {
            break;
        }
        if(contents[i]!=' '){
            str+=contents[i];
        }
    }

    for(int i=(level)*2;i<contents.size();i++){
        if(contents[i]==')')
        {
            break;
        }
        if(start==true){
            value+=contents[i];
        }
        if(contents[i]=='(')
        {
            start=true;
        }
    }

    char seps[] = ",";
    char *token;
    int i=0;
    token = strtok( &value[0], seps );
    while( token != NULL )
    {
        /* Do your thing */
        data[i]=stringToInt(token);
        token = strtok( NULL, seps );
        i++;
    }

    if(str=="CompR"){
       return new CompositeGraphics();
    }else if(str=="C"){
       return new SimpleGraphics(new Circle(data[0],data[1],data[2]));
    }else if(str=="S"){
       return new SimpleGraphics(new Square(data[0],data[1],data[2]));
    }else if(str=="R"){
       return new SimpleGraphics(new Rectangle(data[0],data[1],data[2],data[3]));
    }
}/*implement line 3 */

void GraphicsFactory::compose(){
    //DescriptionVisitor dv;
    if(!compositeObj.empty()){
        while(!compositeObj.empty()){
            Graphics *g = obj.top();
            obj.pop();
            g->add(compositeObj.top());
            obj.push(g);
            compositeObj.pop();
        }
        if(sublevel){
            compose();
        }
    }else{
        int current=level.top();
        if(current!=0){
            while(current==level.top()){
                compositeObj.push(obj.top());
                level.pop();
                obj.pop();
            }
            compose();//compose into a CoobjmpositeGraphics object
        }
    }
    //obj.top()->accept(dv);
    //cout<<dv.getDescription()<<endl;
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
    int tmp;
    if(level.size()>1){
        tmp=level.top();
        level.pop();
        previouslevel=level.top();
        level.push(tmp);
    }
    return previouslevel;
}

int GraphicsFactory::stringToInt(string str){
    int val;
    istringstream is(str);
    is>>val;
    return val;
}

