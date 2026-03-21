class Solution {
public:
    int path(int r,int c,int n,vector<vector<int>>&dp,vector<vector<int>>& triangle){
        if(r==n-1)return triangle[r][c];
        if(dp[r][c]!=-1)return dp[r][c];
        int down=triangle[r][c]+path(r+1,c,n,dp,triangle);
        int diag=triangle[r][c]+path(r+1,c+1,n,dp,triangle);
        return dp[r][c]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp = triangle;
        for(auto &row : dp){
            for(auto &x : row){
             x = -1;
            }
        }
        for(int j=0;j<m;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int r=n-2;r>=0;r--){
            for(int c=r;c>=0;c--){
                int d=triangle[r][c]+dp[r+1][c];
                int dg=triangle[r][c]+dp[r+1][c+1];
                dp[r][c]=min(d,dg);
            }
        }
        return dp[0][0];
    }
};