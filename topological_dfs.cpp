#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node, vector<int> adj[], vector<bool>& vis, stack<int>& s){
        vis[node]=true;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,s);
            }
        }
        s.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;
	    vector<bool> vis(V,false);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,s);
	        }
	    }
	    vector<int>ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=0;i<n;i++){
        cout<<i<<" : ";
        for(auto x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    Solution s;
    vector<int> ans = s.topoSort(n,adj);
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}