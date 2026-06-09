class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini=1LL*INT_MAX,maxi=1LL*INT_MIN;
        for(long long i:nums){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        long long ans=(maxi-mini)*k;
        return ans;
    }
};