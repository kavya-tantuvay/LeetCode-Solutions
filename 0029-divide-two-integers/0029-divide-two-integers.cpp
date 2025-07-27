class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;
        if(dividend==INT_MIN && divisor==-1)return INT_MAX;
        bool sign=true;
        if(dividend<0 && divisor>0)sign=false;
        if(dividend>=0 && divisor<0)sign=false;
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long  long ans=0; long long cnt;
        while(n>=d){
            cnt=0;
            while((d<<(cnt+1))<=n){
                cnt++;     
            }
            n=n-(d<<cnt);
            ans+=1<<cnt;
        }
        if(ans>=INT_MAX && sign==true)return INT_MAX;
        if(ans>INT_MAX && sign==false)return INT_MIN;
        return sign?ans:(-1*ans);
        
    }
};