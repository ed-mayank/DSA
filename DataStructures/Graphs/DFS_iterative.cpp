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

void DFS(vector<int> adj[], int n, int start, vector<int>& dfs){
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    stack<int>s;
    s.push(start);
    visited[start]=true;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        dfs.push_back(t);
        if(dfs.size()==n)return;
        for(auto x:adj[t]){
            if(!visited[x]){
                s.push(x);
                visited[x]=true;
            }
        }
    }   
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