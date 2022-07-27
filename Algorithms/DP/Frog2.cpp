#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll arr[], ll dp[], ll i, ll k){
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    ll cost = INT32_MAX;
    for(ll j=1;j<=k;j++){
        if((i-j) >= 0)
        cost = min(cost, solve(arr,dp,i-j,k)+abs(arr[i]-arr[i-j]));
    }
    return dp[i] = cost;
}

int main(){
    ll n,k;cin>>n>>k;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll dp[n];
    memset(dp,-1,sizeof(dp));
    cout<<solve(arr,dp,n-1,k)<<endl;
}