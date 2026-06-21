class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n=costs.size();
        int i=0;
        int cnt=0;
        while(coins>0 && i<n){
            coins-=costs[i];
            i++;
            if(coins>=0)cnt++;
        }
        return cnt;
    }
};