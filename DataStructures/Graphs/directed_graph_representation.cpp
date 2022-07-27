//Directed Graph representation
#include<bits/stdc++.h>
using namespace std;

void unweightedGraph(vector<int> adj[], int n, int m){
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(u<=n && v<=n){
            adj[u].push_back(v);
        }else{
            cout<<"Inappropriate Input\n";
            exit(0);
        }
    }
}

void weightedGraph(vector<pair<int,int>> adj[],int n,int m){
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(u<=n && v<=n){
            adj[u].push_back(make_pair(v,w));
        }else{
            cout<<"Inappropriate Input\n";
            exit(0);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    // vector<int> adj[n+1];
    // unweightedGraph(adj,n,m);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<": ";
    //     for(auto x:adj[i])cout<<x<<" ";
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
    return 0;
}