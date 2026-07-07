class Solution {
public:
    long long sumAndMultiply(int n) {
        int p=1;
        long long x=0,s=0;
        while(n>0){
            int d=n%10;
            if(d!=0){
                x+=p*d;
                p*=10;
            }
            s+=d;
            n/=10;
        }
        long long ans=1LL*x*s; 
        return ans;
    }
};