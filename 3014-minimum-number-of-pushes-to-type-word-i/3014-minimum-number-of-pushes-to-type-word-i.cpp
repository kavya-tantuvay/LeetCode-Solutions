class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8)return n;
        int ans=0;
        int d=n/8;
        int r=n%8;
        int i=1;
        while(d--){
            ans+=8*i;
            i++;
        }
        ans+=r*i;
        return ans;
    }
};