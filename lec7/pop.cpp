#include<iostream>
using namespace std;

#define MAXSTK 5

void pop(int stack[],int &top,int &item){//function to pop an item from the stack
    if(top==-1){
        cout<<"UNDERFLOW"<<endl;
        return;
    }
    item=stack[top];//assign the top element to item
    top--;//decrease the top pointer
}
int main(){
    int stack[MAXSTK];
    int top=-1;
    int item;

    //pushing some items onto stack
    stack[++top]=10;
    stack[++top]=20;
    stack[++top]=30;

    cout<<"Stack before pop operation:"<<endl;
    for(int i=0;i<=top;i++){
        cout<<stack[i]<<" ";

    }
    cout<<endl;

    //Teasting the pop function
    pop(stack,top,item);
    cout<<"popped item:"<<item<<endl;

    //Display stack content after poping
    cout<<"Stack after pop operation:"<<endl;
    for(int i=0;i<=top;i++){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
    return 0;

}