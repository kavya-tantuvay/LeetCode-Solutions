class Solution {
public:
    int f(int l,int r,vector<int>&nums,vector<vector<int>>&dp){
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int left=nums[l]+min(f(l+1,r-1,nums,dp),f(l+2,r,nums,dp));
        int right=nums[r]+min(f(l,r-2,nums,dp),f(l+1,r-1,nums,dp));
        return dp[l][r]=max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        int s=0;
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i:piles)s+=i;
        int a=f(0,n-1,piles,dp);
        return a>s-a;
    }
};