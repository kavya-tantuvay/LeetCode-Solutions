class Solution {
public:
    // int solve(int ind,int jumps,vector<int>& nums){
    //     int n=nums.size();
    //     if(ind>=n-1)return jumps;
    //     int mini=INT_MAX;
    //     for(int i=1;i<=nums[ind];i++){
    //         mini=min(mini,solve(ind+i,jumps+1,nums));
    //     }
    //     return mini;
    // }
    int jump(vector<int>& nums) {
       int n=nums.size();
       int jumps=0;
       int l=0;
       int r=0;
       while(r<n-1){
        int farthest=0;
        for(int i=l;i<=r;i++){
            farthest=max(farthest,i+nums[i]);  
        }
        l=r+1;
        r=farthest;
        jumps++;
       }
       return jumps;
    }
};