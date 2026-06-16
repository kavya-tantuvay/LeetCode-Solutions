class Solution {
public:
    string processStr(string s) {
        string temp="";
        for (char c:s){
            if(c=='*'){
                if(temp.length()!=0)temp.pop_back();
            }
            else if(c=='#')temp+=temp;
            else if(c=='%')reverse(temp.begin(),temp.end());
            else temp+=c;
        }
        return temp;
    }
};