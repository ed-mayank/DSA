// https://atcoder.jp/contests/dp/tasks/dp_e

#include<bits/stdc++.h>
using namespace std;
long long dp[105][100010];

class Solution{
    public:
    long long func(int index, int w[], int val[], int val_left){
        if(val_left == 0) return 0;
        if(index < 0) return 1e15;
        if(dp[index][val_left] != -1) return dp[index][val_left];
        //dont choose
        long long ans = func(index-1, w,val,val_left);
        // choose
        if((val_left-val[index]) >=0)
        ans = min(ans,func(index-1, w,val,val_left-val[index])+w[index]);

        return dp[index][val_left] = ans;
    }
};

int main(){
    int n,w;cin>>n>>w;
    int weight[n];
    int val[n];
    for(int i=0;i<n;i++){
        cin>>weight[i]>>val[i];
    }
    memset(dp,-1,sizeof(dp));
    int max_val = 1e5;
    Solution S;
    for(int i=max_val;i>=0;i--){
        if(S.func(n-1,weight,val,i) <= w){
            cout<<i<<endl;
            break;
        }
    }
}