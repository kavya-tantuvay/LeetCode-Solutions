class Solution {
public:
    int f(int ind,int tgt,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(tgt%coins[ind]==0)return dp[ind][tgt]=1;
            else return dp[ind][tgt]=0;
        }
        if(dp[ind][tgt]!=-1)return dp[ind][tgt];
        int take=0;
        if(tgt>=coins[ind])take=f(ind,tgt-coins[ind],coins,dp);
        int nottake=f(ind-1,tgt,coins,dp);
        return take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        //return f(n-1,amount,coins,dp);
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)dp[0][t]=1;
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                long long take=0;
                if(t>=coins[i])take=dp[i][t-coins[i]];
                long long nottake=dp[i-1][t];
                dp[i][t]=take+nottake;
            }
        }
        return dp[n-1][amount];
    }
};