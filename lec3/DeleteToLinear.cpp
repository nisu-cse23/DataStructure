#include<iostream>
using namespace std;

int main(){
    int LA[100],N,K,ITEM,J;

    //Task1:Take input for array size
    cout<<"Enter the number of elements:"<<endl;
    cin>>N;

    //Task2:Input array elements
    cout<<"Enter elements of array:"<<endl;
    for(int i=0;i<N;i++){
        cin>>LA[i];
    }

    //Task3:position(k) to delete
    cout<<"Enter the position of the element to delete:"<<endl;
    cin>>K;

    //Task4:convert k to zero based index
     K=K-1;

    //Task5:Store the element  being deleted
    ITEM=LA[K];

    //Task6:Shift the element to the left
    for(J=K;J<N-1;J++){
        LA[J]=LA[J+1];
    }

    //Task7:Decrease the array size
    N=N-1;

    //Task8:Updated array
    cout<<"Updated array after deletion:"<<endl;
    for(int i=0;i<N;i++){
        cout<<LA[i]<<" ";
    }
    return 0;

}