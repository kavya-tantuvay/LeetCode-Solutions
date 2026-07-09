class Solution {
public:
    int summ(int n){
        int s=0;
            while(n>0){
                int d=n%10;
                s+=d*d;
                n/=10;
            }
        return s;
    }
    bool isHappy(int n) {
        unordered_map<int,int>mpp;
        mpp[n]++;
        while(n>=1){
            n=summ(n);
            if(mpp[n]!=0)break;
            mpp[n]++;
        }
        return n==1;
    }
};