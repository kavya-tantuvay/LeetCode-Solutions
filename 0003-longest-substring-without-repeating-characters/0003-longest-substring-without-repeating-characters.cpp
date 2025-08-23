class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int len;
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            ans="";
            ans+=s[i];
            len=1;
            for(int j=i+1;j<n;j++){
                if(ans.find(s[j]) != string::npos)break;
                else {
                    ans+=s[j];
                    len++;
                }
            }
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};