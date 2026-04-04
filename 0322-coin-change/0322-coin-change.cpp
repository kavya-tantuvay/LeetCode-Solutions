class Solution {
public:
    int f(int ind,int t,vector<vector<int>>&dp,vector<int>&coins){
        if(ind==0){
            if(t%coins[0]==0)return dp[ind][t]=t/coins[0];
            else return dp[0][t]=1e9;
        }
        if(dp[ind][t]!=-1)return dp[ind][t];
        int nottake=0+f(ind-1,t,dp,coins);
        int take=1e9;
        if(coins[ind]<=t)take=1+f(ind,t-coins[ind],dp,coins);
        return dp[ind][t]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,amount,dp,coins);
        return ans>=1e9?-1:ans;
    }
};