#include<iostream>
using namespace std;

int main(){
    int LA[100],N,K,ITEM,J;

    //Task1:Take input for array size
    cout<<"Enter the number of elememts:"<<endl;
    cin>>N;

    //Task2:Input array elements
    cout<<"Enter elements of the array:"<<endl;

    for(int i=0;i<N;i++){
        cin>>LA[i];
    }

    //Task3:Input position(K) and new element(ITEM)
    cout<<"Enter the position:"<<endl;
    cin>>K;

    cout<<"Enter the new element:"<<endl;
    cin>>ITEM;

    K=K-1;//convert k to zero based index

    //Task4:Shift elements to the right to make space
    J=N;//Initilaize J to the last index
    while(J>=K){
        LA[J+1]=LA[J];
        J=J-1;
    }
    //Task5:Insert the  new element at position k
    LA[K]=ITEM;

    //Task6:Increase the array size
    N=N+1;

    //Task7:Updated array
    cout<<"Updated array after insertion:"<<endl;

    for(int i=0;i<N;i++){
        cout<<LA[i]<<" ";
    }

    return 0;




}