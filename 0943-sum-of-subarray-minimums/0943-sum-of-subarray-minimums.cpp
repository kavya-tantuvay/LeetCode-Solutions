class Solution {
public:
    vector<int>findnse(vector<int>&arr){
        int n=arr.size();
        vector<int>nse(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findpsee(vector<int>&arr){
        int n=arr.size();
        vector<int>psee(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        int n=arr.size();
        long long ans=0;
        vector<int>nse=findnse(arr);
        vector<int>psee=findpsee(arr);
        for(int i=0;i<n;i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            ans=(ans+(left*right*1ll*arr[i])%mod)%mod;
        }
        return ans%mod;
    }
};