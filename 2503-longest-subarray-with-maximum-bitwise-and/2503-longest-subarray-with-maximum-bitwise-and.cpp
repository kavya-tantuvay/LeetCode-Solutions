class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i:nums)maxi=max(maxi,i);
        int cnt=0;
        int maxcnt=1;
        for(int i=0;i<n;i++){
            while(i<n && nums[i]==maxi){
                cnt++;
                i++;
            }
            maxcnt=max(maxcnt,cnt);
            cnt=0;
        }
        return maxcnt;
    }
};