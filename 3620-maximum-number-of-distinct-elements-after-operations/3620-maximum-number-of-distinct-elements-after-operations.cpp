class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        int current=INT_MIN;
        for(int i:nums){
            int low=i-k;
            int high=i+k;
            if(current+1<=high){
                int assigned=max(current+1,low);
                current=assigned;
                count+=1;
            }
        }
        return count;
    }
};