//https://leetcode.com/problems/coin-change/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int dp[10010];
        int change(vector<int>& coins, int amount){
            if(amount == 0) return 0;
            if(dp[amount] != -1) return dp[amount];
            int ans=INT32_MAX;
            for(auto x:coins){
                if((amount - x) >= 0)
                    ans = min(ans+0LL,change(coins,amount-x)+1LL);
            }
            return dp[amount] = ans;
        }
        int coinChange(vector<int>& coins, int amount) {
            int ans=INT32_MAX;
            memset(dp,-1,sizeof(dp));
            ans = min(ans,change(coins,amount));
            return ans==INT32_MAX ? -1 : ans;
        }
};

int main(){
    int n;cin>>n;
    vector<int>coins;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        coins.push_back(x);
    }
    int amount;cin>>amount;

    Solution S;
    cout<<S.coinChange(coins,amount)<<endl;
}