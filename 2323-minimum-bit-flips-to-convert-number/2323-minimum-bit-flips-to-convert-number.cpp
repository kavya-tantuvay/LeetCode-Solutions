class Solution {
public:
    int countsetbits(int n){
        int cnt=0;
        while(n>1){
            cnt+=n&1;
            n=n>>1;
        }
        if(n)cnt++;
        return cnt;
    }
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        return countsetbits(ans);
    }
};