class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(i>n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int s1=INT_MIN,s2=INT_MIN,s3=INT_MIN;
        if(i<n) s1=nums[i]+min(f(i+2,nums,dp),min(f(i+3,nums,dp),f(i+4,nums,dp)));
        if(i<n && i+1<n) s2=nums[i]+nums[i+1]+min(f(i+3,nums,dp),min(f(i+4,nums,dp),f(i+5,nums,dp)));
        if(i<n && i+1<n && i+2<n) s3=nums[i]+nums[i+1]+nums[i+2]+min(f(i+4,nums,dp),min(f(i+5,nums,dp),f(i+6,nums,dp)));
        return dp[i]=max(s1,max(s2,s3));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size(),-1);
        int a=f(0,stoneValue,dp);
        int s=0;
        for(int i:stoneValue)s+=i;
        int b;
        b=s-a;
        if(a>b)return "Alice";
        else if(a<b)return "Bob";
        else return "Tie";
    }
};