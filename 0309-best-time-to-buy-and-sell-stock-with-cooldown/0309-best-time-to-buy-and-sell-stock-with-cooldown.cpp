class Solution {
public:
    int f(vector<int>& prices,int ind,int buy,int n){
        if(ind>=n)return 0;
        if(buy){
            return max(-prices[ind]+f(prices,ind+1,0,n),f(prices,ind+1,1,n));
        }
        else{
            return max(prices[ind]+f(prices,ind+2,1,n),f(prices,ind+1,0,n));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>f1(2,0);
        vector<int>f2(2,0);
        vector<int>c(2,0);
        for(int i=n-1;i>=0;i--){
            c[1]=max(-prices[i]+f1[0],f1[1]);
            c[0]=max(prices[i]+f2[1],f1[0]);
            f2=f1;
            f1=c;
        }
        return f1[1];
    }
};