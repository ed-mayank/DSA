// https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int func(int i, int j, vector<vector<int>>& v){
        int ans = func(i-1,0,v)+v[i][0];
        ans = max(ans,func(i-1,1,v)+v[i][1]);
        ans = max(ans,func(i-1,2,v)+v[i][2]);

        return ans;
    }
};

int main(){
    int n;cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<3;j++){
            int x;cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
        temp.clear();
    }
    return 0;
}