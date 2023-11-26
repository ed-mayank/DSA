#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n; // m-nodes and n-edges
    cin>>m>>n;
    vector<int> adj[m+1];
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
}