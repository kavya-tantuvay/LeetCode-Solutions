class Solution {
public:
    vector<vector<int>>dir{{+1,0},{-1,0},{0,+1},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==1)health--;
        q.push({health,{0,0}});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>best(n,vector<int>(m,-1));
        best[0][0]=health;
        while(!q.empty()){
            auto it=q.front();
            int h=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1 && h>=1)return true;
            q.pop();
            for(auto d:dir){
                int nr=r+d[0];
                int nc=c+d[1];
                int nh;
                if(nr>=0 && nr<n && nc<m && nc>=0){
                    if(grid[nr][nc]==1)nh=h-1;
                    else nh=h;
                    if(nh>0 && nh>best[nr][nc]){
                    best[nr][nc]=nh;
                    q.push({nh,{nr,nc}});
                     }
                }
            }
        }
        return false;
    }
};