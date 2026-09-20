class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int sum=0;int r;
        for(int i=1;i<=n;i++){
            r=26-(s[i-1]-'a');
            sum+=r*i;
        }
        return sum;
    }
};