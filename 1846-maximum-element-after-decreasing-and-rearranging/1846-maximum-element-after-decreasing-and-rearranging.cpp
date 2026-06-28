class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        int maxi=1;
        sort(arr.begin(),arr.end());
        vector<int>temp=arr;
        if(temp[0]>1)temp[0]=1;
        for(int i=1;i<n;i++){
            if(abs(temp[i]-temp[i-1])<=1);
            else temp[i]=temp[i-1]+1;
            maxi=max(maxi,temp[i]);
        }
        return maxi;
    }
};
