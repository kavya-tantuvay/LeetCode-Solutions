class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxi(n),mini(n);
        int maxx=INT_MIN,minn=INT_MAX;
        for(int i=0;i<n;i++){
            maxx=max(maxx,nums[i]);
            maxi[i]=maxx;
            
        }
        for(int i=n-1;i>=0;i--){
            minn=min(minn,nums[i]);
            mini[i]=minn;
        }
        
        for(int i=0;i<n;i++){
            int sc=maxi[i]-mini[i];
            if(sc<=k)return i;
        }
        return -1;
    }
};