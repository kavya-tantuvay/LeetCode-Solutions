class Solution {
public:
    int rev(int x){
        int r=0;
        while(x>0){
            r=r*10+x%10;
            x/=10;
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(mpp.count(nums[i])){
                ans=min(ans,i-mpp[nums[i]]);
            }
            mpp[rev(nums[i])]=i;
        }
        return ans==1e9?-1:ans;
    }
};