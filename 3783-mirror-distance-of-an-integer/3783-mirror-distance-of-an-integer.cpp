class Solution {
public:
    int mirrorDistance(int n) {
        int m=n;
        int rev=0;
        while(n>0){
            int d=n%10;
            rev=rev*10+d;
            n/=10;
        }
        return abs(rev-m);
    }
};