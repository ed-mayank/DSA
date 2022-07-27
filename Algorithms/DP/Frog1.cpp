#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve(ll arr[], ll dp[], ll i){
    ll cost = INT32_MAX;
    if(i==0) return 0;
    if(dp[i] != -1) return dp[i];

    cost = min(cost, solve(arr,dp,i-1) + abs(arr[i]-arr[i-1]));
    if(i > 1)
    cost = min(cost,solve(arr,dp,i-2)+abs(arr[i]-arr[i-2]));

    return dp[i] = cost;
}

int main(){
    ll n;cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll dp[n];
    memset(dp,-1,sizeof(dp));
    cout << solve(arr,dp,n-1)<<endl;
}