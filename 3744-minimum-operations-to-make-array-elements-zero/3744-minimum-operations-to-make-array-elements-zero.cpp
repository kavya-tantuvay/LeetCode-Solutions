class Solution {
public:
    long long get(int x){
        long long cur=1;
        long long res=0;
        int mul=1;
        while(cur<=x){
            long long next=min(cur*4,(long long)x+1);
            long long cnt=next-cur;
            res+=cnt*mul;
            mul++;
            cur*=4;
        }
        return res;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(auto q:queries){
            int l=q[0];
            int r=q[1];
            long long req=get(r)-get(l-1);
            ans+=(req+1)/2;
        }
        return ans;
    }
};