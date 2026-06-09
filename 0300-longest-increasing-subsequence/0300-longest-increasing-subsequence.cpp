class Solution {
public:
    int f(vector<int>& nums,int ind,int prev,vector<vector<int>>&dp){
        if(ind==nums.size())return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev])take=1+f(nums,ind+1,ind,dp);
        int not_take=f(nums,ind+1,prev,dp);
        return dp[ind][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp);
    }
};