class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int s=nums[1];int ss=INT_MAX;
        for(int i=2;i<n;i++){
            if(nums[i]<s){
                ss=s;
                s=nums[i];
            }
            else if(nums[i]>=s && nums[i]<ss){
                ss=nums[i];
            }
        }
        return nums[0]+s+ss;
    }
};