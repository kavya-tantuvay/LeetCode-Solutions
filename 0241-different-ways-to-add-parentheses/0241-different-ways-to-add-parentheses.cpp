class Solution {
public:
    vector<int> solve(int i,int j,string s){
        vector<int>ans;
        bool isNumber = true;

        for(int k=i;k<=j;k++){
            if(s[k]=='+' || s[k]=='-' || s[k]=='*'){
                isNumber = false;
                break;
            }
        }
        if(isNumber){
        ans.push_back(stoi(s.substr(i,j-i+1)));
        }


        for(int ind=i+1;ind<=j;ind++){
            if(s[ind]=='-'||s[ind]=='+'||s[ind]=='*'){
            vector<int>left=solve(i,ind-1,s);
            vector<int>right=solve(ind+1,j,s);
            for(int l:left){
                for(int r:right){
                    if(s[ind]=='-')ans.push_back(l-r);
                    else if(s[ind]=='+')ans.push_back(l+r);
                    else ans.push_back(l*r);
                }
            }
            }
            
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.length();
        return solve(0,n-1,expression);
    }
};