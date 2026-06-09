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
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                for(int c=1;c<=2;c++){
                    if(b){
                        dp[i][b][c]=max(-prices[i]+dp[i+1][0][c],0+dp[i+1][1][c]);
                    }
                    else{
                        dp[i][b][c]=max(prices[i]+dp[i+1][1][c-1],0+dp[i+1][0][c]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};