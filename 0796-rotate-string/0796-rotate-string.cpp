class Solution {
public:
    bool rotateString(string s, string goal) {
        string ss=s+s;
        return (goal.length()==s.length()) && (ss.find(goal)!=string::npos);
    }
};