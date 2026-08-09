class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            int num=i;
            int cnt=0;
            while(num!=0){
                num=num&(num-1);
                cnt++;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};