class Solution {
public:
    int f(int l,int r,vector<int>&nums){
        if(l>r)return 0;
        int take_l=nums[l]+min(f(l+2,r,nums),f(l+1,r-1,nums));
        int take_r=nums[r]+min(f(l+1,r-1,nums),f(l,r-2,nums));
        return max(take_l,take_r);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int s1=f(0,n-1,nums);
        int s=0;
        for(auto i:nums)s+=i;
        int s2=s-s1;
        return s1>=s2;
    }
};