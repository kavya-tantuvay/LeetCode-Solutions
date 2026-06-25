class Solution {
public:
    string process(string s){
        int n=s.size();
        int i=0,j=0;
        string temp="";
        while(i<n){
            int cnt=0;
            while(j<n && s[j]==s[i]){
                cnt++;
                j++;
            }
            temp+=to_string(cnt);
            temp+=s[i];
            i=j;
        }
        return temp;
    }
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        return process(countAndSay(n-1));
    }
};