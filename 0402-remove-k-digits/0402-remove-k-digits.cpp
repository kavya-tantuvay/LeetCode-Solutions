class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())return "0";
        stack<char>st;
        for(char i:num){
            while(!st.empty() && st.top()-'0'>i-'0' && k>0){
                st.pop();
                k--;
            }
            st.push(i);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.empty())return "0";
        return res;
    }
};