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
            long long req=get(q[1])-get(q[0]-1);
            ans+=(req+1)/2;
        }
        return ans;
    }
};