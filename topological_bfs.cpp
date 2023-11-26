#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    vector<int>ans;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
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