class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        }
        for(auto it:mpp){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};