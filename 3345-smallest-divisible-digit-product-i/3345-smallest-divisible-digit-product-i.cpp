class Solution {
public:
    bool possible(int n,int t){
        int ans=1;
        while(n>0){
            int d=n%10;
            ans*=d;
            n/=10;
        }
        return ans%t==0;
    }
    int smallestNumber(int n, int t) {
         while(!possible(n,t)){
            n+=1;
         }
         return n;
    }
};