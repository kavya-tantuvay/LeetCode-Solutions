class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return -1;
        int mini=INT_MAX;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto it:mpp){
            if(it.second.size()<3)continue;
            vector<int>v=it.second;
            int n=v.size();
            for(int i=0;i<n-2;i++){
                int j=v[i];
                int k=v[i+2];
                mini=min(2*abs(k-j),mini);
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};