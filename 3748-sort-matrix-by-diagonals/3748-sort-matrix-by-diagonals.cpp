class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,deque<int>>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[i-j].push_back(grid[i][j]);
            }
        }
        for(int i=-(m+n-1);i<m+n;i++){
            if(i<0){
                sort(mpp[i].begin(),mpp[i].end());
            }
            else{
                sort(mpp[i].begin(),mpp[i].end(),greater<int>());
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               int key=i-j;
               grid[i][j]=mpp[key].front();
               mpp[key].pop_front();
            }
        }
        return grid;

    }
};