class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=0;
        long long total=0;
        long long maxf=0;
        while(r<n){
            total+=nums[r];
            while(nums[r]*(long long)(r-l+1)>total+k){
                total-=nums[l];
                l++;
            }
            maxf=max(maxf,(long long)(r-l+1));
            r++;
        }
        return (int)maxf;
    }   
};