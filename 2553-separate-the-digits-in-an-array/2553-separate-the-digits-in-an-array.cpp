class Solution {
public:
    void req(int num,vector<int>&ans){
        vector<int>temp;
        int n=num;
        while(n!=0){
            int d=n%10;
            temp.push_back(d);
            n/=10;     
        }
        reverse(temp.begin(),temp.end());
        for(int it:temp){
            ans.push_back(it);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto it:nums){
            req(it,ans);
        }
        return ans;
    }
};