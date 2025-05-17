#include<iostream>
#include<stack>
#include<string>
using namespace std;

string removeAdjDuplicates(string s){
    stack<char>stk;

    for(char c:s){
        if(!stk.empty() && stk.top()==c){
            stk.pop();//remove the duplicate character
        }
        else{
            stk.push(c);//add the current character to the stack
        }
    }
    if(stk.empty()){
        return "Empty string";
    }
    
    //construct the resulting string from the stack
    string result=" ";
    while(!stk.empty()){
        result=stk.top()+result;
        stk.pop();
    }
    return result;
}
int main(){
    string str;

    cout<<"Enter a string:";
    cin>>str;

    cout<<removeAdjDuplicates(str)<<endl;
    return 0;
}