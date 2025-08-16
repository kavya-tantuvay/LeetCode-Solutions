class Solution {
public:
    int maximum69Number (int num) {
        int maxi=num;
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            maxi=max(maxi,stoi(s));
            if(s[i]=='9'){
                s[i]='6';
            }
            else{
                s[i]='9';
            }
            maxi=max(maxi,stoi(s));
            if(s[i]=='9'){
                s[i]='6';
            }
            else{
                s[i]='9';
            }
        }
        return maxi;
    }
};