class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>hash;
        int m=t.size();
        int n=s.size();
        int cnt=m;
        int l=0,r=0;
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        int sind=-1;
        int minlen=INT_MAX;
        while(r<n){
           if(hash[s[r]]>0){
             cnt--;
           }
           hash[s[r]]--;
           while(cnt==0){
            if(r-l+1<minlen){
                minlen=r-l+1;
                sind=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0)cnt++;
            l++;
           }
           r++;
        }
        return sind==-1?"":s.substr(sind,minlen);
    }
};