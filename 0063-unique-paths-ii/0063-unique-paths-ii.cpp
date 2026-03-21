class Solution {
public:
    int path(int r,int c,vector<vector<int>>&dp,vector<vector<int>>&nums){
        if(r==0 && c==0)return 1;
        if((r<0 || c<0) || nums[r][c]==1)return 0;
        if(dp[r][c]!=-1)return dp[r][c];
        int left=path(r,c-1,dp,nums);
        int right=path(r-1,c,dp,nums);
        return dp[r][c]=left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(m-1,n-1,dp,obstacleGrid);
    }
};