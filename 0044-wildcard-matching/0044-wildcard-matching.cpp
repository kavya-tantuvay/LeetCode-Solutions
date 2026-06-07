class Solution {
public:
    bool f(vector<vector<int>>&dp,string &s,string &p,int i,int j){
        if(j==0 && i==0)return dp[i][j]=true;
        if(j==0 && i>=1)return dp[i][j]=false;
        if(i==0 && j>=1){
            for(int ind=0;ind<j;ind++){
                if(p[ind]!='*')return dp[i][j]=false;
            }
            return dp[i][j]=true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==p[j-1] || p[j-1]=='?')return dp[i][j]=f(dp,s,p,i-1,j-1);
        
        if(p[j-1]=='*'){   
            bool skip=f(dp,s,p,i,j-1);
            bool keep=f(dp,s,p,i-1,j);
            return dp[i][j]=skip||keep;
         }
        return dp[i][j]=false; 
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(dp,s,p,n,m);
    }
};