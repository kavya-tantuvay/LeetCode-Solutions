class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>hash(26,0);
        int n=s.size();
        int l=0;
        int r=0;
        int maxf=0;
        int maxlen=0;
        //len-maxf, 
        while(r<n){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            while((r-l+1)-maxf>k){
                hash[s[l]-'A']--;
                l++;
            }
            maxlen=max((r-l+1),maxlen);
            r++;
        }
        return maxlen;
    }
};