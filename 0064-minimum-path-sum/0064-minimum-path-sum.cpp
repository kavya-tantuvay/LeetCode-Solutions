class Solution {
public:
    int path(int r,int c,vector<vector<int>>&dp,vector<vector<int>>&grid){
        if(r==0 && c==0)return grid[0][0];
        if(r<0 || c<0)return 1e9;
        if(dp[r][c]!=-1)return dp[r][c];
        int up=path(r-1,c,dp,grid);
        int left=path(r,c-1,dp,grid);
        return dp[r][c]=min(grid[r][c]+left,grid[r][c]+up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return path(n-1,m-1,dp,grid);
    }
};