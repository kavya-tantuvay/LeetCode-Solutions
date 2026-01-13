class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int same=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int drow[4]={+1,-1,0,0};
        int dcol[4]={0,0,+1,-1};
         vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sr][sc]=1;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr<n && nr>=0 && nc<m && nc>=0 && image[nr][nc]==same && image[nr][nc]!=color){
                    vis[nr][nc]=1;
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
        
    }
};