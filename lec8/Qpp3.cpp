
#include<iostream>
#include<stack>
using namespace std;

//Function to process the string with backspaces and return the resultant string
string processString(string s){

    stack<char>st;
    for(char ch:s){
        if(ch=='#'){
            if(!st.empty()){
                st.pop();
            }
        }
            else{
                st.push(ch);
            }
        }

 //build the resultant string from the stack
 string result=" ";
 while(!st.empty()){
    result=st.top()+result;//prepend characters to the result
    st.pop();
 } 

   return result;   

    }

 //Function to compare two processed strings
 bool areEqual(string s1,string s2){
    return processString(s1)==processString(s2);
 
}
int main(){
    string s1,s2;

    cout<<"Enter first string s1:";
    cin>>s1;

    cout<<"Enter second string s2:";
    cin>>s2;

    if(areEqual(s1,s2)){
        cout<<"Output:True"<<endl;
    }
    else{
        cout<<"output:False"<<endl;
        return 0;
    }
}