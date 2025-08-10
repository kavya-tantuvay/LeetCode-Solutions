class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        unordered_map<int,int>nge;
        stack<int>st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty())nge[nums2[i]]=-1;
            else{
                nge[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        for(int i:nums1){
            ans.push_back(nge[i]);
        }
        return ans;
    }
};