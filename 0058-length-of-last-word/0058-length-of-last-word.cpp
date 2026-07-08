class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(s[i]==' ')i++;
        while(s[j]==' ')j--;
        int l=i;
        int r=j;
        while(r>=l && s[r]!=' '){
            r--;
        }
        if(r==l)return j-r+1;
        return j-r;
    }
};