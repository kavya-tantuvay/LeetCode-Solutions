class Solution {
public:
    int summ(int n){
        int s=0;
        while(n>0){
            int d=n%10;
            s+=d;
            n/=10;
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i:nums){
            mini=min(mini,summ(i));
        }
        return mini;
    }
};