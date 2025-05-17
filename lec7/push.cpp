#include<iostream>
using namespace std;

#define MAXSTK 5//maximum size of rhe stack

void PUSH(int stack[],int &top,int item){
    if(top==MAXSTK-1){
        cout<<"Overflow"<<endl;
        return ;
    }
    top++;
    stack[top]=item;
}

int main(){
    int stack[MAXSTK];//Stack array
    int top=-1;//initialize top of stack as -1(empty stack)
    int item;

    //Task1:testing the push function
    cout<<"Enter an item to push onto stack:";
    cin>>item;

    PUSH(stack,top,item);

    //Task2:Display stack content
    cout<<"Stack top:"<<stack[top]<<endl;
    return 0;
}

