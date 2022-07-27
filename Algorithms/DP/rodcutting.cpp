// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int dp[1010];
    int rod(vector<int>& prices, int n){
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans=0;
        for(int i=1;i<=prices.size();i++){
            if((n-i) >= 0)
            ans = max(ans,rod(prices,n-i)+prices[i-1]);
        }
        return dp[n] = ans;
    }
    int cutRod(int price[], int n){
        memset(dp,-1,sizeof(dp));
        vector<int>prices(price,price+n);
        return rod(prices,n);
    }
};

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution S;
    cout<<S.cutRod(arr,n)<<endl;
}