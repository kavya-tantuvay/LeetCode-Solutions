class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mpp;
        for(char ch:text){
            mpp[ch]++;
        }
        int b=mpp['b'];
        int a=mpp['a'];
        int l=mpp['l'];
        int o=mpp['o'];
        int n=mpp['n'];
        int ans=min(b,min(a,min(l/2,min(o/2,n))));
        return ans;
    }
};