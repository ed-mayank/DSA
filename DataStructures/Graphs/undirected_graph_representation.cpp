//Representation of undirected Graph
#include<bits/stdc++.h>
using namespace std;

void UnweightedGraph(vector<int> adj[], int n, int m){
    for(int i=0;i<m;i++){
        int v,u;
        cin>>u>>v;  //u-v
        if(u<=n && v<=n){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }else{
            cout<<"Inappropriate input\n";
            exit(0);
        }
    }
}

void weightedGraph(vector<pair<int,int>> adj[], int n, int m){
    for(int i=0;i<m;i++){
        int v,u,w;
        cin>>u>>v>>w;
        if(u<=n && v<=n){
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }else{
            cout<<"Inappropriate Input\n";
            exit(0);
        }
    }
}

int main(){
    int n,m; //n-#nodes/vertex and m-#edges
    cout<<"Enter n and m: ";
    cin>>n>>m;
    // vector<int>adj[n+1]; //considering 1 based indexing (unweighted graph)
    // UnweightedGraph(adj,n,m);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<": ";
    //     for(auto x:adj[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<pair<int,int>> adj[n+1];
    weightedGraph(adj,n,m);
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(auto x:adj[i]){
            cout<<"("<<x.first<<","<<x.second<<") ";
        }
        cout<<endl;
    }
}