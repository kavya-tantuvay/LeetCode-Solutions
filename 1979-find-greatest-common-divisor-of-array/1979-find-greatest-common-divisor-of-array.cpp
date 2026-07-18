class Solution {
public:
    int gcd(int a,int b){
        while(a>0 && b>0){
            if(a>b)a%=b;
            else b%=a;
        }
        if(a==0)return b;
        return a;
    }
    int findGCD(vector<int>& nums) {
        int mini=nums[0];
        int maxi=nums[0];
        for(int i:nums){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        return gcd(mini,maxi);
    }
};