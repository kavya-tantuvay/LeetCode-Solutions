class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> open;
        string res;
        for (char c: s) {
            if (c == '(') {
                open.push(res.length());
            } else if (c == ')') {
                int start = open.top();
                open.pop();
                reverse(res.begin() + start, res.end());
            } else {
                res += c;
            }
        }
        return res;
    }
};