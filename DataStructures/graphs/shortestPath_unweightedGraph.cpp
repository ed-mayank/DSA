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
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

void shortestPath(unordered_map<int,list<int>> &adj, int src, int dest, vector<int> &ans){
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto x: adj[front]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
                parent[x] = front;
            }
        }
    }

    int currNode = dest;
    ans.push_back(currNode);
    while(currNode != src){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    for(auto x: parent){
        cout<<x.first<<"->"<<x.second<<endl;
    }
    reverse(ans.begin(), ans.end());
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

    vector<int> ans;
    shortestPath(g.adj,0,7,ans);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
/*
Sample Graph
9 12
0 1
0 2
0 3
1 3
1 4
2 5
3 6
4 6
5 6 
5 8
6 7
7 8
*/