class Solution {
public:
    void shiftt(vector<vector<int>>&nums, vector<vector<int>>&ans){
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++){
                ans[i][j+1]=nums[i][j];
            }
        }
        for(int i=1;i<n;i++){
            ans[i][0]=nums[i-1][m-1];
        }
        ans[0][0]=nums[n-1][m-1];
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& nums, int k) {
        vector<vector<int>>ans=nums;
        while(k--){
            shiftt(nums,ans);
            nums=ans;
        }
        return ans;
    }
};