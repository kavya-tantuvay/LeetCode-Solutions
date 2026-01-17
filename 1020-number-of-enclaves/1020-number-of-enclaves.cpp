class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&grid,int n,int m){
       grid[r][c]=0;
       int dr[4]={+1,-1,0,0};
       int dc[4]={0,0,+1,-1};
       for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                grid[nr][nc]=0;
                dfs(nr,nc,grid,n,m);
            }
       }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 ||i==n-1 ||j==0 ||j==m-1){
                    if(grid[i][j]==1){
                        dfs(i,j,grid,n,m);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};