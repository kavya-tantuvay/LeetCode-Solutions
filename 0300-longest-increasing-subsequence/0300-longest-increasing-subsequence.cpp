class Solution {
public:
    int f(vector<int>& nums,int ind,int prev,vector<vector<int>>&dp){
        if(ind==nums.size())return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev])take=1+f(nums,ind+1,ind,dp);
        int not_take=f(nums,ind+1,prev,dp);
        return dp[ind][prev+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int prev=ind-1;prev>=-1;prev--){
        //         int len=dp[ind+1][prev+1];
        //         if(prev==-1 || nums[ind]>nums[prev])len=max(len,1+dp[ind+1][ind+1]);
        //         dp[ind][prev+1]=len;
        //     }
        // }
        // return dp[0][0];
        vector<int>temp;
        temp.push_back(arr[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
                len++;
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                temp[ind]=arr[i];
            }
        }
        return len;
    }
};