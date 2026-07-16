class Solution {
public:
    int gcd(int a,int b){
        while(a>0 && b>0){
            if(a>b)a=a%b;
            else b=b%a;
        }
        if(a==0)return b;
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pg(n);
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            pg[i]=gcd(nums[i],maxi);
        }
        sort(pg.begin(),pg.end());
        int l=0;
        int r=n-1;
        long long summ=0;
        while(l<r){
            summ+=gcd(pg[l],pg[r]);
            l++;
            r--;
        }
        return summ;
    }
};