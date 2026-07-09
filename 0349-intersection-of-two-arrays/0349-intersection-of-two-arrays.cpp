class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        unordered_map<int,int>mpp;
        for(int i:nums1)mpp[i]++;
        for(int i=0;i<m;i++){
            if(mpp[nums2[i]]>0 && find(ans.begin(),ans.end(),nums2[i])==ans.end())ans.push_back(nums2[i]);
    
        }
        return ans;
    }
};