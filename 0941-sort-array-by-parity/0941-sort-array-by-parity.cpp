class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>even,odd;
        for(int i:nums){
            if(i%2==0)even.push_back(i);
            else odd.push_back(i);
        }
        for(int i:odd){
            even.push_back(i);
        }
        return even; 
    }
};