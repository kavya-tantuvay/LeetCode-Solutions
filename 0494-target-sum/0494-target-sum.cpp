class Solution {
public:
    int f(int ind,int t,vector<int>&nums){
        if(ind==0){
            if(+nums[ind]==t && -nums[ind]==t)return 2;
            if(+nums[ind]==t || -nums[ind]==t)return 1;
            return 0;
        }
        int plus=f(ind-1,t-nums[ind],nums);
        int minus=f(ind-1,t-(-nums[ind]),nums);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,target,nums);
    }
};