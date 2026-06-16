class Solution {
public:
    int maxx(vector<int>&nums,int i,int j){
        int maxi=nums[i];
        for(int k=i;k<=j;k++){
            maxi=max(maxi,nums[k]);
        }
        return maxi;
    }
    int f(int i,int n,int k,vector<int>&arr,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi=0;
        for(int j=i;j<n;j++){
            if(j-i+1<=k){
                int r=maxx(arr,i,j);
                int summ=(j-i+1)*r+f(j+1,n,k,arr,dp);
                maxi=max(maxi,summ);
            }
        }
        return dp[i]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(0,n,k,arr,dp);
    }
};