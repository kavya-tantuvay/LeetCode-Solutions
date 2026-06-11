class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),cnt(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && dp[i]<dp[prev]+1){
                    dp[i]=max(dp[i],1+dp[prev]);
                    cnt[i]=cnt[prev];
                }
                else if(dp[prev]+1==dp[i]){
                    cnt[i]+=cnt[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int s=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)s=s+cnt[i];
        }
        return s;
    }
};