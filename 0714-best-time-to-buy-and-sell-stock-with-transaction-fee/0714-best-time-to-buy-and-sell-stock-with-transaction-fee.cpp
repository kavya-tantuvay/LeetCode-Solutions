class Solution {
public:
    int f(vector<int>& prices, int fee,int n,int ind,int buy){
        if(ind==n)return 0;
        if(buy){
            return max(-prices[ind]+f(prices,fee,n,ind+1,0),f(prices,fee,n,ind+1,1));
        }
        else{
            return max(prices[ind]+f(prices,fee,n,ind+1,1)-fee,f(prices,fee,n,ind+1,0));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>a(2,0);
        vector<int>c(2,0);
        for(int i=n-1;i>=0;i--){
            c[1]=max(-prices[i]+a[0],a[1]);
            c[0]=max(prices[i]+a[1]-fee,a[0]);
            a=c;
        }
        return a[1];
    }
};