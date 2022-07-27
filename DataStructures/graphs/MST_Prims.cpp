/*
When we convert graph into tree such that it has n nodes and n-1 edges and each node is reachable from other node then it
is called spanning tree.
when total cost of edges is minimum for the all spanning tree is MST.

Prims Algorithm:
1. key array
2. MST track array
3. Parent array
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

void MST_Prims(unordered_map<int,list<pair<int,int>>> &adj, int n, vector<tuple<int,int,int>> &ans){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // vector for keys and initilize all with inf
    vector<int> key(n,INT32_MAX);

    // vector to keep track of nodes if they are included in MST
    vector<bool> isMST(n,false);

    // vector to keep track of parent
    vector<int> parent(n,-1);

    int src = 0;
    pq.push(make_pair(0,src));
    key[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(!isMST[u]){
            isMST[u]=true;

            for(auto x: adj[u]){
                int v = x.second;
                int weight = x.first;
                if(isMST[v]==false && key[v]>weight){
                    key[v] = weight;
                    pq.push(make_pair(weight,v));
                    parent[v]=u;
                }
            }
        }
    }

    for(int i=1;i<n;i++){
        ans.push_back(make_tuple(parent[i],i,key[i]));
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
    vector<tuple<int,int,int>> ans;
    MST_Prims(g.adj,n,ans);
    for(int i=0;i<ans.size();i++){
        cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<endl;
    }
    return 0;
}