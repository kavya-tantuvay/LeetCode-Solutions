class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i:nums)mpp[i]++;
        int n=nums.size();
        int d,m;
        for(int i=1;i<=n;i++){
            if(mpp[i]==2)d=i;
            if(mpp[i]==0)m=i;
        }
        return {d,m};
    }
};