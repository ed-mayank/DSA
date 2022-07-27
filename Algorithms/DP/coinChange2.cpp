//https://leetcode.com/problems/coin-change-2/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int dp[310][10000];
        int totalCombination(int index, int amount, vector<int>& coins){
            int ans=0;
            if(amount == 0){
                return 1;
            }
            if(index<0){
                return 0;
            }
            if(dp[index][amount] != -1){
                return dp[index][amount];
            }

            for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[index]){
                ans+=totalCombination(index-1,amount-coin_amount,coins);
            }
            return dp[index][amount]=ans;
        }

        int change(int amount, vector<int>& coins) {
            memset(dp,-1,sizeof(dp));
            int ans = totalCombination(coins.size()-1,amount,coins);
            return ans;
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
    cout<<S.change(amount,coins)<<endl;
}