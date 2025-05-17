#include<iostream>
#include<string>
using namespace std;

int main(){
    char T[100],P[100];
    int S=0,R=0,K=0,MAX,INDEX=0;
    bool found;

    cout<<"Enter the main text:"<<endl;
    cin.getline(T,100);

    cout<<"Enter the pattern to search:"<<endl;
    cin.getline(P,100);

    while(T[S]!=0){
        S++;
    }
    while(P[R]!=0){
        R++;

    }

    MAX=S-R+1;
    K=0;

   while(K<MAX){
     found=true;
     for(int L=0;L<R;L++){
    if(P[L]!=T[K+L]){
        found =false;
        break;
    }
   }

   if(found){
     INDEX=K+1;
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