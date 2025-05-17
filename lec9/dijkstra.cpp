#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

const int INF=numeric_limits<int>::max();
vector<int>dijkstra(int numOfnodes,vector<vector<pair<int,int>>>&roads,int startnode){
    vector<int>distance(numOfnodes,INF);
    distance[startnode]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,startnode});//{distance,node}

    while(!pq.empty()){
        int currentdistance=pq.top().first;
        int currentnode=pq.top().second;
        pq.pop();

        if(currentdistance>distance[currentnode]){
            continue;
        }

            for(int i=0;i<roads[currentnode].size();i++){
                int neighbor=roads[currentnode][i].first;
                int weight=roads[currentnode][i].second;
                

                if(distance[currentnode]+weight <distance[neighbor]){
                    distance[neighbor]=distance[currentnode]+weight;
                    pq.push({distance[neighbor],neighbor});
                }


            }
        }
        return distance;
    }
int main(){
    int n=5;
    vector<vector<pair<int,int>>>roads(n);
    
    roads[0].push_back({1,10});
    roads[0].push_back({4,5});
    roads[1].push_back({2,1});
    roads[1].push_back({4,2});
    roads[2].push_back({3,4});
    roads[3].push_back({0,7});
    roads[3].push_back({2,6});
    roads[4].push_back({1,3});
    roads[4].push_back({2,9});
    roads[4].push_back({3,2});

    int startnode=0;
    vector<int>result=dijkstra(n,roads,startnode);

    cout<<"Shortest distances from node" << startnode <<":\n";
    for(int i=0;i<n;i++){
        if(result[i]==INF){
            cout<< "node"<<i<<":unreachable\n";
        }
        else{
            cout<<" node"<<i<<":"<<result[i]<<"\n";
        
        }

        }
        return 0;
    }

