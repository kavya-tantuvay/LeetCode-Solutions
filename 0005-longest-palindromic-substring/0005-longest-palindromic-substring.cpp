class Solution {
public:
    string exp(int i,int j,string s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1)return s;
        string ans="";
        for(int i=0;i<n;i++){
            string odd=exp(i,i,s);
            if(odd.size()>ans.size())ans=odd;
            string even=exp(i,i+1,s);
            if(even.size()>ans.size())ans=even;
        }
        return ans;
    }
};