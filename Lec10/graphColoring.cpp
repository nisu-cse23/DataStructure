#include<iostream>
#include<vector>

using namespace std;
bool isSafe(int v,const vector<vector<int>>&graph,const vector<int>&colors,int col){
    for(int i=0;i<graph[v].size();i++){
        int neighbor=graph[v][i];
        if(colors[neighbor]==col){
            return false;//Neighbor haas the same color
        }
    }
    return true;
}
bool assignColors(int v,const vector<vector<int>>&graph,int maxColors, vector<int>&colors){
    int totalvertices=graph.size();
    if(v==totalvertices){
        return true;//all vertices arre colored
    }
    for(int col=1;col<=maxColors;col++){
        if(isSafe(v,graph,colors,col)){
            colors[v]=col;
            if(assignColors(v+1,graph,maxColors,colors)){
                return true;
            }
            colors[v]=0;
        }
    }
    return false;
}
bool colorgraph(const vector<vector<int>>&graph,int maxColors, vector<int>&colors){
    return assignColors(0,graph,maxColors,colors);
}

int main(){
   vector<vector<int>> graph(4);//4 nodes

graph[0].push_back(1);
graph[0].push_back(2);
graph[1].push_back(0);
graph[1].push_back(2);
graph[2].push_back(0);
graph[2].push_back(1);
graph[2].push_back(3);
graph[3].push_back(2);

    int maxColors=3;

    vector<int>colors(graph.size(),0);
    if(colorgraph(graph,maxColors,colors)){
        cout<<"Graph coloring possible:\n";
        for(int i=0;i<colors.size();i++){
            cout<<"Node"<<i<<"-> color"<<colors[i]<<'\n';
        }
    }
    else{
        cout<<"Graph coloring not possible with"<<maxColors<<"colors.\n";
    }
    return 0;

}