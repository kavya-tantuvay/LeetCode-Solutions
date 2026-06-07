class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int a0,a1,c0,c1;
        a0=0;a1=0;
        int profit=0;
        for(int ind=n-1;ind>=0;ind--){
            c1=max(-prices[ind]+a0,0+a1);
            c0=max(prices[ind]+a1,0+a0);
            a0=c0;
            a1=c1;
        }
        return a1;
    }
};