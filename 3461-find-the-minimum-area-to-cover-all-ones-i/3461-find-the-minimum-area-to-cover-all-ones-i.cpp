class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minarea=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        int fc=m,fr=n,lc=-1,lr=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fc=min(fc,j);
                    fr=min(fr,i);
                    lc=max(lc,j);
                    lr=max(lr,i);
                }
            }
        }
        return ((lc-fc+1)*(lr-fr+1));
    }
};