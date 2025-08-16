class Solution {
public:
    int histogram(vector<int>&nums){
        stack<int>st;
        int n=nums.size();
        int maxi=0;
        int nse,pse;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                int element=nums[st.top()];
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                int area=element*(nse-pse-1);
                maxi=max(maxi,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            int element=nums[st.top()];
            st.pop();
            pse=st.empty()?-1:st.top();
            int area=element*(nse-pse-1);
            maxi=max(maxi,area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxrec=0;
        vector<vector<int>>presum(n, vector<int>(m, 0));
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=matrix[j][i]-'0';
                if(matrix[j][i]=='0')sum=0;
                presum[j][i]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxrec=max(maxrec,histogram(presum[i]));
        }
        return maxrec;
    }
};