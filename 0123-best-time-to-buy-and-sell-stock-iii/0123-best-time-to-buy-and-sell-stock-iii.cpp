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
        vector<int>after(5,0);
        vector<int>cur(5,0);
        for(int i=n-1;i>=0;i--){
            for(int t=3;t>=0;t--){
                
                    if(t%2==0){
                        cur[t]=max(-prices[i]+after[t+1],0+after[t]);
                    }
                    else{
                        cur[t]=max(prices[i]+after[t+1],0+after[t]);
                    }
                    after=cur;
                
            }
        }
        return after[0];
    }
};