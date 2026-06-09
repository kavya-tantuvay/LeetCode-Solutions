class Solution {
public:
    void f(vector<int>& nums,int n,int ind,vector<int>&ans){

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int lastind=0,maxi=1;
        vector<int>dp(n,1),hash(n,0);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastind=i;
            }
        }
        vector<int>ans(maxi,0);
        ans[0]=nums[lastind];int ind=1;
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            ans[ind++]=nums[lastind];
        }
        
        return ans;
    }
};