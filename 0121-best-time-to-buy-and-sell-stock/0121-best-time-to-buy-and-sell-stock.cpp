class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxp=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            maxp=max(maxp,cost);
            mini=min(mini,prices[i]);
        }
        return maxp;
    }
};