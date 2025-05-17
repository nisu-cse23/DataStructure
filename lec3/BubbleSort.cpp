#include<iostream>
using namespace std;

int main(){
    int DATA[100],N,PTR,K,temp;

    cout<<"ENter the number of elements:"<<endl;
    cin>>N;

    cout<<"Enter elements of the array:"<<endl;
    for(int i=0;i<N;i++){
        cin>>DATA[i];
    }

    //Task1: For bubble sort
    for(K=1;K<=N-1;K++){//number of passes
        PTR=1; //Initilaize PTR for each pass
        while(PTR<=N-K){//compparing adjacent element
            if(DATA[PTR-1]>DATA[PTR]){//swap
                temp=DATA[PTR-1];
                DATA[PTR-1]=DATA[PTR];
                DATA[PTR]=temp;
            }
            PTR=PTR+1;//move to the next pair
        }
    }

    //Task2:Displat the result
    cout<<"Array After bubble sort:"<<endl;
    for(int i=0;i<N;i++){
        cout<<DATA[i]<<" ";
    }
    return 0;
}