class Solution {
public:
    
    int f(int i,int n,int k,vector<int>&arr,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi=0;
        int maxans=0;
        int len=0;
        for(int j=i;j<min(i+k,n);j++){
            len++;
            maxi=max(arr[j],maxi);
            int summ=len*maxi+f(j+1,n,k,arr,dp);
            maxans=max(maxans,summ);
            
        }
        return dp[i]=maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(0,n,k,arr,dp);
    }
};