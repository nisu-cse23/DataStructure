#include<iostream>
using namespace std;

int main(){
    char A[100],B[100];
    int n,m,L[101][101];

    cout<<"Enter first string A:"<<endl;
    cin>>A;

    cout<<"Enter second string B:"<<endl;
    cin>>B;

    
    while(A[n]!=0){//for length
        n++;
    }
    while(B[m]!=0){
        m++;
    }

    for(int i=0;i<=n;i++){
        L[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        L[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]){//If characters match
              L[i][j]=L[i-1][j-1]+1;
            }
            else{//not match then take max value
            if(L[i-1][j]>L[i][j-1]){
                L[i][j]=L[i-1][j];
            }
            else{
                L[i][j]=L[i][j-1];
            }
            
        }
    }
}
cout<<"Length of LCS:"<<L[n][m]<<endl;
return 0;
}