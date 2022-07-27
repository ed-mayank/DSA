#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
    public:
    unordered_map<T, list<T>> adj;

    void addEdge(int u, int v, bool isDirected){
        adj[u].push_back(v);

        if(!isDirected){
            adj[v].push_back(u);
        }
    }

    void printgraph(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

void bfs(unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();

        ans.push_back(temp);
        for(auto i: adj[temp]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    graph<int> g;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,false);
    }
    unordered_map<int,bool> visited;
    vector<int> ans;
    bfs(g.adj,visited,ans,0);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}