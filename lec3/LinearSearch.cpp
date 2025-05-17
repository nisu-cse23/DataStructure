#include<iostream>
using namespace std;

int main(){
    int DATA[100],N,ITEM,LOC,k;

    //Task1:Take input for the array size
    cout<<"Enter the number of elemets:"<<endl;
    cin>>N;

    //Task2:Input array elements
    cout<<"Enter elements of the array:"<<endl;
    for(int i=0;i<N;i++){
        cin>>DATA[i];
    }

    //Task3:Input the element (Item) to search
    cout<<"Enter the ITEM to search:"<<endl;
    cin>>ITEM;

    //Task4:Insert Item at the end of DATA
    DATA[N]=ITEM;
    LOC=1;//inilialize counter loc =1
  

    //Task6:Linear search check each element
   while(DATA[LOC-1]!=ITEM){
    LOC=LOC+1;
   }
    

    //Task6:Not found
    if(LOC==N+1){
        LOC=0;
        cout<<"ItEM not found in the array."<<endl;

    }
    else{
        cout<<"ITEM found at position: "<<LOC<<endl;
    }
    return 0;
}