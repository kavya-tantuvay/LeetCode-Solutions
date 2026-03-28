class Solution {
public:
    bool f(vector<int>&nums,int k){
        int n=nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(k+1,0));
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(k>=nums[0])dp[0][nums[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int tgt=1;tgt<=k;tgt++){
                bool nottake=dp[ind-1][tgt];
                bool take=false;
                if(tgt>=nums[ind])take=dp[ind-1][tgt-nums[ind]];
                dp[ind][tgt]=nottake || take;
            }
        }
        return dp[n-1][k]; 
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum%2==1)return false;
        return f(nums,sum/2);
    }
};