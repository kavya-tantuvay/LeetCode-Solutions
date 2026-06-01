class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int n=cost.size();
        int r=0;
        for(int i=0;i<n;i++){
            if(i%3!=2)r+=cost[i];
        }
        return r;
    }
};