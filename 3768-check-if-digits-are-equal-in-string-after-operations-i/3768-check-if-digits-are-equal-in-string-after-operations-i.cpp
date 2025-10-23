class Solution {
public:
    bool hasSameDigits(string s) {
        
        string str=s;
        while(str.size()>2){
            int n=str.size();
            string temp="";
            for(int i=0;i<n-1;i++){
                int r=(str[i]-'0'+str[i+1]-'0')%10;
                string j=to_string(r);
                temp+=j;
            }
            str=temp;
        }
        return str[0]==str[1];
    }
};