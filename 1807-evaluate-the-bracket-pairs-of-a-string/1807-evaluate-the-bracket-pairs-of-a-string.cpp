class Solution {
public:
    string find(string tgt,vector<vector<string>>& dict,int n){
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(dict[m][0]<tgt){
                l=m+1;
            }
            else if(dict[m][0]>tgt)h=m-1;
            else if(dict[m][0]==tgt){
                return dict[m][1];
            }
        }
        return "?";
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=knowledge.size();
        sort(knowledge.begin(),knowledge.end());
        int l=s.length();
        string ans="";
        int i=0;
        while(i<l){
            char ch=s[i];
            if(ch=='('){
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp+=s[i];
                    i++;
                }
                ans+=find(temp,knowledge,n);
            }
            else ans+=ch;
            i++;
        }
        return ans;
    }
};