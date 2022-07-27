#include<bits/stdc++.h>
using namespace std;

template<typename T>

class graph{
    public:
    unordered_map<T,list<T>>adj;

    void addEdge(T u, T v, bool isDirected){
        adj[u].push_back(v);

        if(isDirected == false){
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

int main(){
    graph<int> g;
    int n,m;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,false);
    }
    g.printGraph();
    return 0;
}