//Longest Increasing subsequence
//dp
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int lis(vector<int>& v,int dp[], int i){
            int ans=1;
            if(dp[i] != -1) return dp[i];
            for(int j=0;j<i;j++){
                if(v[j]<v[i]){
                    ans = max(ans,lis(v,dp,j)+1);
                }
            }
            return dp[i] = ans;
        }

        int lengthOfLIS(vector<int>& v){
            int dp[v.size()];
            memset(dp,-1,sizeof(dp));
            int ans=0;
            for(int i=0;i<v.size();i++){
                ans=max(ans,lis(v,dp,i));
            }
            return ans;
        }
};

int main(){
    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    Solution S;
    cout<<S.lengthOfLIS(v)<<endl;
    return 0;
}



//937066
//732896289830