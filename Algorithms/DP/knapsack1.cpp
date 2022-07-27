// https://atcoder.jp/contests/dp/tasks/dp_d

#include<bits/stdc++.h>
using namespace std;
long long dp[105][100010];

class Solution{
    public:
    long long func(int index, int weight[], int values[], int capacity){
        if(capacity==0) return 0;
        if(index<0) return 0;
        if(dp[index][capacity] != -1) return dp[index][capacity];
        long long ans=0;
        if((capacity-weight[index]) >= 0)
            ans = func(index-1, weight, values, capacity-weight[index]) + values[index];
        ans = max(ans,func(index-1, weight,values, capacity));

        return dp[index][capacity] = ans;
    }
};

int main(){
    int n,w;cin>>n>>w;
    int weight[n];
    int values[n];
    for(int i=0;i<n;i++){
        cin>>weight[i]>>values[i];
    }
    Solution S;
    memset(dp,-1,sizeof(dp));
    cout<<S.func(n-1,weight,values,w)<<endl;

}