class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len=nums.size();
        int n=len/2;
        unordered_map<int,int>mpp;
        for(int a:nums){
            mpp[a]++;
        }
        for(auto it:mpp){
            if(it.second==n)return it.first;
        }
        return 0;
    }
};