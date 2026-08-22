class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0,s1=0,s2=1;
        int m=n;
        while(m>0){
            int d=m%10;
            s1+=d;
            s2*=d;
            m/=10;
        }
        s=s1+s2;
        return !(n%s);
    }
};