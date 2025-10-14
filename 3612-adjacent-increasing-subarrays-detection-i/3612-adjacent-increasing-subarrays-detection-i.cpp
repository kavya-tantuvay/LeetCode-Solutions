class Solution {
public:
    bool strictlyinc(vector<int>&nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1])return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<=n-2*k;i++){
            vector<int> v1(nums.begin()+i,nums.begin()+i+k);
            vector<int> v2(nums.begin()+i+k,nums.begin()+i+k+k);
            if(strictlyinc(v1) && strictlyinc(v2))return true;
        }
        return false;
    }
};