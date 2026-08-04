class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=nums[0];
        int r=nums[n-1];
        if(n==r-l+1)return ans;
        for(int i=l+1;i<r;i++){
            if(find(nums.begin(), nums.end(), i) == nums.end())ans.push_back(i);
        }
        return ans;
    }
};