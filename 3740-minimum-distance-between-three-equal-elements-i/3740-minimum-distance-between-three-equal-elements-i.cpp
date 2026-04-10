class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return -1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]!=nums[j])continue;
                for(int k=j+1;k<n;k++){
                    if(nums[j]==nums[k]){
                        int x=abs(i-j)+abs(j-k)+abs(k-i);
                        mini=min(mini,x);
                    }
                }
            }
        }
        if(mini==INT_MAX)return -1;
        return mini;
    }
};