#include<string.h>
string get_code(string input){
    int len=input.size();
    string temp="";
    temp.push_back(input.at(0));
    int flag=1;
    for(int i=0;i<len;i++){
        if(input.at(i)==' '){
                temp.push_back(input.at(i+1));
                flag=0;
        }
    }
    if(flag){
            temp.push_back(input.at(1));
            temp.push_back(input.at(2));
    }
    if(temp=="Mat"){
        return "maths";
    }
    if(temp=="CO"){
        return "COA";
    }
     if(temp=="Dat"){
        return "DBM";
    }
    if(temp=="Mic"){
        return "MP";
    }
    if(temp=="not"||temp=="bla"||temp=="Bla"){
        return "---";
    }
    if(temp=="CS"){
        return "c#";
    }
    if(temp=="Uni"){
        return "UNIX";
    }
    return temp;
}
