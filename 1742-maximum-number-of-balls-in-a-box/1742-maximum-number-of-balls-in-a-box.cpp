class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int maxi=0;
        vector<int>ans(46,0);
        for(int i=lowLimit;i<=highLimit;i++){
            int num=i;
            int s=0;
            while(num>0){
                int d=num%10;
                s+=d;
                num/=10;
            }
            ++ans[s];
            maxi=max(maxi,ans[s]);
        }
        return maxi;
    }
};