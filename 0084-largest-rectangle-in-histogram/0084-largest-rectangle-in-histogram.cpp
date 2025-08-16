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
        int maxi=0;
        stack<int>st;
        int nse,pse;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int element=st.top();
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                int area=heights[element]*(nse-pse-1);
                maxi=max(maxi,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            int element=st.top();
            st.pop();
            pse=st.empty()?-1:st.top();
            int area=heights[element]*(nse-pse-1);
            maxi=max(maxi,area);
        }

        return maxi;
    }
};