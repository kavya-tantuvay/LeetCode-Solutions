class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n==1)return 1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        int dr[8]={0,-1,0,+1,-1,+1,-1,+1};
        int dc[8]={-1,0,+1,0,+1,-1,-1,+1};
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<n && nc<n && nr>=0 && nc>=0 && grid[nr][nc]==0 && dist[nr][nc]>dis+1){
                    dist[nr][nc]=dis+1;
                    if(nr==n-1 && nc==n-1)return dis+1;
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return -1;
    }
};