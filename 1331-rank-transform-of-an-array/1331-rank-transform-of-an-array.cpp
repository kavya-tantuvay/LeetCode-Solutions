class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);
        vector<int>temp=arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mpp;
        int ind=1;
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]==arr[i-1])continue;
            mpp[arr[i]]=ind++;
        }
        for(int i=0;i<n;i++){
            ans[i]=mpp[temp[i]];
        }
        return ans;
    }
};