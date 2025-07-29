class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int bitindex=0; bitindex<=31; bitindex++){
            int cnt=0;
            for(int i=0; i<n;i++){
                if(nums[i]&(1<<bitindex))cnt++;
            }
            if(cnt%3==1){
                ans=ans|(1<<bitindex);
            }
        }
        return ans;
    }
};