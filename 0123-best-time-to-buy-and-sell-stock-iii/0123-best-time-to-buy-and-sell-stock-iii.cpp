class Solution {
public:
    int f(vector<vector<vector<int>>>&dp,vector<int>&prices,int ind,int buy,int cnt,int n){
        if(cnt==0)return 0;
        if(ind==n)return 0;
        int profit=0;
        if(dp[ind][buy][cnt]!=-1)return dp[ind][buy][cnt];
        if(buy==1){
            profit=max(0+f(dp,prices,ind+1,1,cnt,n),-prices[ind]+f(dp,prices,ind+1,0,cnt,n));
        }
        else{
            profit=max(0+f(dp,prices,ind+1,0,cnt,n),prices[ind]+f(dp,prices,ind+1,1,cnt-1,n));
        }
        return dp[ind][buy][cnt]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(dp,prices,0,1,2,n);
    }
};