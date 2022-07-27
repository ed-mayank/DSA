/*
1. Create set or priority queue.
2. Take out top element of set/pq and check if its distance to its neighbouring node is less than updated in dist array.
if less, push that dist, node pair into set/pq back.

Time complexity: O(E*logV)
Space complexity: Linear O(E+V)
*/

#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addEdge(int u, int v, int w, bool isDirected){
        adj[u].push_back(make_pair(w,v));
        if(!isDirected){
            adj[v].push_back(make_pair(w,u));
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

void dijkstra(unordered_map<int,list<pair<int,int>>> &adj, int n, int src, vector<int> &ans){
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        ans[i] = INT32_MAX;
    }
    ans[src]=0;
    s.insert(make_pair(ans[src],src));
    while(!s.empty()){
        pair<int,int> top = *s.begin();
        s.erase(s.begin());
        int nodeDist = top.first;
        int node = top.second;

        for(auto neighbour: adj[node]){
            int dist = neighbour.first;
            if(ans[neighbour.second] > (nodeDist+dist)){
                ans[neighbour.second] = nodeDist+dist;
                s.insert(make_pair(nodeDist+dist,neighbour.second));
            }
        }
    }
}

int main(){
    graph<int> g;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w,0);
    }
    g.printGraph();

    vector<int> ans(n);
    dijkstra(g.adj,n,1,ans);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}

/*
5 7
0 1 7
0 2 1
0 3 2
1 2 3
1 4 1
1 3 5
3 4 7
*/