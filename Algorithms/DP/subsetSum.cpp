// https://leetcode.com/problems/partition-equal-subset-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int dp[205][20005];
    bool partition(int i, int sum, vector<int>& nums){
        if(sum == 0) return true;
        if(i < 0) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        bool ans = partition(i-1, sum, nums); // dont choose
        if((sum-nums[i])>= 0)
            ans = ans | partition(i-1, sum-nums[i],nums); // choose
        return dp[i][sum] = ans;
    }

    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2) return false;
        sum = sum/2;
        return partition(nums.size()-1, sum, nums);
    }
};

int main(){
    int n;cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        nums.push_back(x);
    }
    Solution S;
    cout<<S.canPartition(nums)<<endl;
    return 0;
}