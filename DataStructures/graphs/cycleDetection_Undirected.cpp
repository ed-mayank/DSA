#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
    public:
    unordered_map<T,list<T>> adj;

    void addEdge(int u, int v, bool isDirected){
        adj[u].push_back(v);
        if(!isDirected){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

bool cycleDetection_BFS(unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, int src){
    unordered_map<int,int> parent;
    queue<int>q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto x:adj[front]){
            if(visited[x] && x != parent[front]){
                return true;
            }
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
                parent[x] = front;
            }
        }
    }
    return false;
}


bool cycleDetection_DFS(int src, int parent, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited){
    visited[src] = true;
    for(auto neighbour: adj[src]){
        if(!visited[neighbour]){
            bool ans = cycleDetection_DFS(neighbour,src,adj,visited);
            if(ans) return true;
        }
        else if(neighbour != parent){
            return true;
        }
    }
    return false;
}

int main(){
    graph<int> g;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printGraph();
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = cycleDetection_BFS(g.adj,visited,i);
            if(ans) {
                cout<<"YES"<<endl;
                exit(0);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         bool ans = cycleDetection_DFS(i,-1,g.adj,visited);
    //         if(ans) {
    //             cout<<"YES"<<endl;
    //             exit(0);
    //         }
    //     }
    // }
    cout<<"NO"<<endl;
    return 0;
}