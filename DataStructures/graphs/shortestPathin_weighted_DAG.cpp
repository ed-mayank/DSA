/*
Steps:
1. Find topological sort.
2. create a distance array for all nodes and fill initially with infinity.
3. Start with top of stack and if it src node and replace dist[src] = 0;
4. Now iterate to all neighbour of top element if dist[top] != inf and then replace with distance of that node from top node.
*/


#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
    public:
    unordered_map<T,list<pair<T,T>>> adj;

    void addEdge(int u, int v, int w, bool isDirected){
        adj[u].push_back(make_pair(v,w));
        if(!isDirected){
            adj[v].push_back(make_pair(u,w));
        }
    }

    void printGraph(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<"{"<<j.first<<","<<j.second<<"},";
            }
            cout<<endl;
        }
    }
};

void topologicalSort(unordered_map<int,list<pair<int,int>>> &adj, stack<int> &s, unordered_map<int,bool> &visited,int node){
    visited[node] = true;
    for(auto neighbour: adj[node]){
        if(!visited[neighbour.first]){
            topologicalSort(adj, s, visited, neighbour.first);
        }
    }
    s.push(node);
}

int shortestPathLength(unordered_map<int,list<pair<int,int>>> &adj, int src, int dest,int n){
    stack<int> s;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i])
        topologicalSort(adj,s,visited,i);
    }
    
    int dist[n];

    for(int i=0;i<n;i++){
        dist[i] = INT32_MAX;
    }
    
    dist[src] = 0;
    while(!s.empty()){
        int top = s.top();
        s.pop();
        if(dist[top] != INT32_MAX){
            for(auto x: adj[top]){
                if(dist[top]+x.second < dist[x.first]){
                    dist[x.first] =  dist[top]+x.second; 
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<"->"<<dist[i]<<endl;
    }
    return dist[dest];
}

int main(){
    graph<int> g;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w,1);
    }
    g.printGraph();

    cout<<shortestPathLength(g.adj, 1, 5,n)<<endl;
    return 0;
}
/*
Sample Graph:
6 9
0 1 5
0 2 3
1 2 2
1 3 6
2 3 7
2 4 4
2 5 2
3 4 -1
4 5 -2
*/