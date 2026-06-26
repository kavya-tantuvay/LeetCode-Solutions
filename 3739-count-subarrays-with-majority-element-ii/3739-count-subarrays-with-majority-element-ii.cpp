class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int cumsum=0;
        long long ans=0,vlp=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int n=nums.size();
        for(int j=0;j<n;j++){
            if(nums[j]==target){
                vlp+=mpp[cumsum];
                cumsum+=1;
            }
            else{
                cumsum-=1;
                vlp-=mpp[cumsum];
            }
            mpp[cumsum]++;
            ans+=vlp;
        }
        return ans;
    }
};