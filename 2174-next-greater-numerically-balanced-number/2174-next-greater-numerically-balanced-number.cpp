class Solution {
public:
    bool isvalid(string s){
        int n=s.size();
        vector<int>f(10,0);
        for(int i=0;i<n;i++){
            f[s[i]-'0']++;
        }
        for(char c:s){
            if(f[c-'0']!=c-'0')return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int x=n+1;
        while(true){
            if(isvalid(to_string(x)))return x;
            x++;
        }
        return -1;
    }
};