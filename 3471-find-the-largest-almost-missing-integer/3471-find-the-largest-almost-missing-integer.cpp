class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=nums[0];
        unordered_map<int,int>mpp;
        for(int i:nums){mpp[i]++;maxi=max(maxi,i);}
        if(k==n)return maxi;
        if(k==1){
            int mm=-1;
            for(int i:nums){
                if(mpp[i]==1)mm=max(mm,i);
            }
            return mm;
        }
        int a=mpp[nums[0]];
        int b=mpp[nums[n-1]];
        if(a==1 && b==1)return max(nums[0],nums[n-1]);
        else if(a==1)return nums[0];
        else if(b==1)return nums[n-1];
        return -1;
    }
};