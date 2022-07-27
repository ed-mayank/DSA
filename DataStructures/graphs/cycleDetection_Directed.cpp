// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

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

bool cycleDetection_DFS(int node, unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited){
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool isCycleDetected = cycleDetection_DFS(neighbour, adj, visited, dfsVisited);
            if(isCycleDetected) return true;
        }
        else{
            // Node is visited
            if(dfsVisited[neighbour]){
                return true;
            }
        }
    }
    
    // returning from function call 
    dfsVisited[node] = false;
    return false;
}

// Cycle detection using BFS (Kahn's algorithm)

void cycleDetection_topologicalSort_BFS(unordered_map<int,list<int>> &adj, unordered_map<int,int> &indegree, int &count){
    queue<int> q;
    for(auto i: indegree){
        if(i.second == 0){
            q.push(i.first);
        }
    }
    while(!q.empty()){
        int front = q.front();
        q.pop();
        count++;
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

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    // for(int i=1;i<=n;i++){
    //     if(!visited[i]){
    //         bool ans = cycleDetection_DFS(i,g.adj,visited, dfsVisited);
    //         if(ans) {
    //             cout<<"YES"<<endl;
    //             exit(0);
    //         }
    //     }
    // }
    // cout<<"NO"<<endl;



    // Cycle Detection using BFS
    unordered_map<int,int> indegree;
    for(int i=1;i<n;i++){
        indegree[i]=0;
    }
    for(auto x: g.adj){
        for(auto i: x.second){
            indegree[i]++;
        }
    }
    int count=0;
    cycleDetection_topologicalSort_BFS(g.adj,indegree,count);
    if(count == n){
        cout<<"No cycle present\n";
    }else{
        cout<<"Graph is cyclic\n";
    }
    return 0;
}