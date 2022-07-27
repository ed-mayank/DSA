// Can be applied on DAG only.

#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u, int v, bool isDirected){
        adj[u].push_back(v);
        if(!isDirected){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

void topologicalSort_DFS(int node, unordered_map<int,list<int>> adj, vector<bool> &visited, stack<int> &s){
    visited[node] = true;
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topologicalSort_DFS(neighbour,adj,visited,s);
        }
    }
    s.push(node);
}

void topologicalSort_Kahn(unordered_map<int,list<int>> &adj, unordered_map<int,int> &indegree, vector<int> &ans){
    queue<int>q;
    for(auto i: indegree){
        if(i.second == 0){
            q.push(i.first);
        }
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto x: adj[front]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
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
        g.addEdge(u,v,1);
    }
    g.printGraph();

    //Topological Sort using DFS
    vector<bool> visited(n);
    stack<int>s;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            topologicalSort_DFS(i,g.adj,visited,s);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;



    // Topological Sort using Kahn's alogrithm
    unordered_map<int,int> indegree;
    for(int i=1;i<n;i++){
        indegree[i]=0;
    }
    for(auto x: g.adj){
        for(auto i: x.second){
            indegree[i]++;
        }
    }
    vector<int> ans;
    topologicalSort_Kahn(g.adj,indegree,ans);
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}