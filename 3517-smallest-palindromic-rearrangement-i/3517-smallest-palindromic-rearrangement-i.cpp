class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1)return s;
        string temp="";
        for(int i=0;i<n/2;i++){
            temp+=s[i];
        }
        sort(temp.begin(),temp.end());
        string rtemp=temp;
        reverse(rtemp.begin(),rtemp.end());
        if(n%2==0)return temp+rtemp;
        return temp+s[n/2]+rtemp;

    }
};