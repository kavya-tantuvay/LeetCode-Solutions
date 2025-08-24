class Solution {
public:
    int le(vector<int>&nums,int k){
        int n=nums.size();
        if(k<0)return 0;
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        while(r<n){
            sum+=(nums[r]%2);
            while(sum>k){
                sum-=(nums[l]%2);
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return le(nums,k)-le(nums,k-1);
    }
};