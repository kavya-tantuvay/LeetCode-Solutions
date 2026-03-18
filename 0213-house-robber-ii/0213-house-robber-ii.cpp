class Solution {
public:
    int rob1(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        int curi;
        for(int i=1;i<n;i++){
            int take=nums[i]+prev2;
            int nottake=0+prev;
            curi=max(take,nottake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>temp1(nums.begin(),nums.end()-1);
        vector<int>temp2(nums.begin()+1,nums.end());
        int f=rob1(temp1);
        int s=rob1(temp2);
        return max(f,s);
    }
};