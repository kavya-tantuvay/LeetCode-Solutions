class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       long long XORR=0;
       for(int i:nums)XORR^=i;
       long long rightmost=XORR&(XORR-1)^ XORR;
        int b1=0;
        int b2=0;
        for(int i:nums){
            if(i&rightmost)b1^=i;
            else b2^=i;
        }
        return {b1,b2};
    }
};