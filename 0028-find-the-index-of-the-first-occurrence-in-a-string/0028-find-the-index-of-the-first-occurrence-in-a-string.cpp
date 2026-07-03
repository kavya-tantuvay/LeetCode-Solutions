class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int>LPS(m,0);
        int len=0;
        int ind=1;
        while(ind<m){
            if(needle[ind]==needle[len]){
                len++;
                LPS[ind]=len;
                ind++;
            }
            else{
                if(len!=0){
                    len=LPS[len-1];
                }
                else{
                    LPS[ind]=0;
                    ind++;
                }
            }
        }
        int i=0,j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==m)return i-j;
            else if(i<n && haystack[i]!=needle[j]){
            if(j!=0)j=LPS[j-1];
            else i++;
            }
        }
        return -1;
    }
};