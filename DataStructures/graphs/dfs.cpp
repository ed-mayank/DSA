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

void dfs(unordered_map<int,list<int>> &adj, int node, vector<int> &ans, unordered_map<int,bool> &visited){
    if(visited[node] == true){
        return;
    }

    ans.push_back(node);
    visited[node] = true;
    for(auto i : adj[node]){
        dfs(adj,i,ans,visited);
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
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(g.adj,i,ans,visited);
        }
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
