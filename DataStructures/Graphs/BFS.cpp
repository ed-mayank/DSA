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

void BFS(vector<int>adj[],int n, int start, vector<int>& bfs){
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int s = q.front();
        bfs.push_back(s);
        if(bfs.size()==n)return;
        q.pop();
        for(auto x: adj[s]){
            if(!visited[x]){
                q.push(x);
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
    vector<int>bfs;
    int start;
    cout<<"Enter start node for BFS traversal: ";
    cin>>start;
    BFS(adj,n,start,bfs);
    for(auto x:bfs){
        cout<<x<<" ";
    }
    cout<<endl;
}