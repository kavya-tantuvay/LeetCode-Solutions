class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int r=2*k;
        vector<int>after(r+1,0);
        vector<int>cur(r+1,0);
        for(int i=n-1;i>=0;i--){
            for(int t=r-1;t>=0;t--){
                if(t%2==0){
                    cur[t]=max(-prices[i]+after[t+1],after[t]);
                }
                else{
                    cur[t]=max(prices[i]+after[t+1],after[t]);
                }
                after=cur;
            }
        }
        return after[0];
    }
};