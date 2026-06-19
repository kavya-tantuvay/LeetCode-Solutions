class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int cost=0;
        for(auto it:gain){
            cost+=it;
            maxi=max(maxi,cost);
        }
        return maxi;
    }
};