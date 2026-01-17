class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>& board,int n,int m){
    
     vis[r][c]=1;
     int drow[4]={+1,-1,0,0};
     int dcol[4]={0,0,+1,-1};
     for(int i=0;i<4;i++){
        int nr=r+drow[i];
        int nc=c+dcol[i];
        if(nr<n && nr>=0 && nc<m && nc>=0 && board[nr][nc]=='O' && vis[nr][nc]==0){
            vis[nr][nc]=1;
            dfs(nr,nc,vis,board,n,m);
        }
     }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(board[i][j]=='O'){
                        dfs(i,j,vis,board,n,m);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
       
    }
};