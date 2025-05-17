#include<iostream>
using namespace std;

int main(){
    char T[100],P[100];
    int S=0,R=0,K=1,MAX,INDEX=0;
    int SK=0;

    cout<<"Enter the main test:"<<endl;
    cin.getline(T,100);

    cout<<"Enter pattern to search:"<<endl;
    cin.getline(P,100);

    while(T[S]!=0){//for length
        S++;
    }
    while(P[R]!=0){
        R++;
    }

    MAX=S-R+1;

    while(SK!=R && K<=S){
        SK+0;

     while(SK<R && P[SK]==T[K+SK-1]){
        SK++;
     }  

     if(SK==R){
        INDEX=K;
        break;
     } 
     K++;

    }
    if(INDEX==0){
        cout<<"pattern not found"<<endl;
    }
    else{
        cout<<"Pattern found at position:"<<INDEX<<endl;
    }
    return 0;

}