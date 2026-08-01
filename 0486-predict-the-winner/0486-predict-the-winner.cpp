class Solution {
public:
    int f(int l,int r,vector<int>&nums){
        if(l>r)return 0;
        if(l==r)return nums[l];
        int left=nums[l]+min(f(l+2,r,nums),f(l+1,r-1,nums));
        int right=nums[r]+min(f(l,r-2,nums),f(l+1,r-1,nums));
        return max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i:nums)s+=i;
        int s1=f(0,n-1,nums);
        int s2=s-s1;
        return s1>=s2;
    }
};