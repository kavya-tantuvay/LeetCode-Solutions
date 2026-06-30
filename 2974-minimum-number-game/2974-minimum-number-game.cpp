class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,0);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i%2==0){
                arr[i]=nums[i+1];
            }
            else arr[i]=nums[i-1];
        }
        return arr;
    }
};