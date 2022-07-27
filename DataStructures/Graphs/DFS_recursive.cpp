#include<bits/stdc++.h>
using namespace std;

void Graph(vector<int> adj[], int n, int m){
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

void DFSUtil(vector<int>adj[],int v, bool visited[], vector<int>& dfs){
    visited[v]=true;
    dfs.push_back(v);
    for(auto x:adj[v]){
        if(!visited[x]){
            DFSUtil(adj,x,visited,dfs);
        }
    }
}

void DFS(vector<int> adj[], int n, int start, vector<int>& dfs){
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    DFSUtil(adj,start,visited,dfs);
}

int main(){
    int n,m;
    cout<<"Enter number of nodes(n) and edges(m): ";
    cin>>n>>m;
    vector<int>adj[n+1];
    Graph(adj,n,m);
    vector<int>dfs;
    int start;
    cout<<"Enter start node for DFS traversal: ";
    cin>>start;
    DFS(adj,n,start,dfs);
    for(auto x:dfs)cout<<x<<" ";
    cout<<endl;
}