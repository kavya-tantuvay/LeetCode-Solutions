class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        for(char c:s){
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            }
            else{
            if(st.empty())return false;
            else{
                char top=st.top();
                st.pop();
                if((c==')' && top=='(')||(c==']' && top=='[')||(c=='}' && top=='{')){}
                else{
                    return false;
                }
            }
            }
        }
        return st.empty();
    }
};