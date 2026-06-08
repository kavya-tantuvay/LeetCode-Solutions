class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans,left,middle,right;
        for(int it:nums){
            if(it<pivot)left.push_back(it);
            else if(it>pivot)right.push_back(it);
            else(middle.push_back(it));
        }
        for(int it:left){
            ans.push_back(it);
        }
        for(int it:middle){
            ans.push_back(it);
        }
        for(int it:right){
            ans.push_back(it);
        }
        return ans;  
    }
};