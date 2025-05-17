#include<iostream>
#include<stack>
#include<sstream>

using namespace std;

void reversewords(string text){

    stack<string>words;
    stringstream ss(text);
    string word;

    //push words into the stack
    while(ss>>word){
        words.push(word);
    }

    //pop and print words from the stack
    while(!words.empty()){
        cout<<words.top()<< " ";
        words.pop();
    }
    cout<<endl;
}
int main(){
    string input="techenical Interview Preparation";

    cout<<"Input:"<<input<<endl;
    cout<<"output:";
    reversewords(input);
    return 0;

}