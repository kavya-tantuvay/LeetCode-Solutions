class Solution {
public:
    bool ispal(string &temp){
        int n=temp.size();
        int i=0,j=n-1;
        while(i<j){
            if(temp[i]!=temp[j])return false;
            i++;j--;
        }
        return true;
    }
    int f(int i,int n,string &s,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        string temp="";
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(ispal(temp)){
                int cost=1+f(j+1,n,s,dp);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return f(0,n,s,dp)-1;
    }
};