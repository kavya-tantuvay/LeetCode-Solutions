class Solution {
public:
    int totalMoney(int n) {
       int total=0;
       int prev=0;
       int cnt=0;
        for(int i=1;i<=n;i++){
            if((i%7)==1)prev++;
            if(i%7==0)cnt=prev+6;
            else cnt=prev+((i%7)-1);
            total+=cnt;
        }
        return total;
    }
};