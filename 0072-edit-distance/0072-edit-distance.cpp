class Solution {
public:
    int f(vector<vector<int>>&dp,string s,string t,int i,int j){
        if(i==0)return dp[i][j]=j;
        if(j==0)return dp[i][j]=i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1])return f(dp,s,t,i-1,j-1);
        else{
            int rep=1+f(dp,s,t,i-1,j-1);
            int ins=1+f(dp,s,t,i,j-1);
            int dlt=1+f(dp,s,t,i-1,j);
            return dp[i][j]=min(rep,min(ins,dlt));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(dp,word1,word2,n,m);
    }
};