#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
        vector<int> parent, rank, size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        
        // path compression
        int find(int i){
            if(parent[i] == i) return i;

            return parent[i] = find(parent[i]);
        }

        void unionByRank(int u, int v){
            int ulp_u = this->find(u);
            int ulp_v = this->find(v);

            if(ulp_u == ulp_v) return;   // Part of same set

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_u]=ulp_v;
                rank[ulp_v]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = find(u);
            int ulp_v = find(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};

int main(){
    DisjointSet ds(6);
    ds.unionBySize(0,1);
    ds.unionBySize(2,3);
    ds.unionBySize(2,4);
    ds.unionBySize(1,5);

    if(ds.find(1) == ds.find(3)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Different"<<endl;
    }
    ds.unionBySize(5,3);
    if(ds.find(1) == ds.find(3)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Different"<<endl;
    }
}
