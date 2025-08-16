class Solution {
public:
    vector<int>findnse(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>nse(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& nums[st.top()]>=nums[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findpse(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>pse(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty()&& nums[st.top()]>=nums[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse,pse;
        nse=findnse(heights);
        pse=findpse(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            int area=heights[i]*(nse[i]-pse[i]-1);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};