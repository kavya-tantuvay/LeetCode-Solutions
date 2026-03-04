class Solution {
public:
    bool valid(int r,int c,int n,int m,vector<vector<int>>& mat){
        for(int j=0;j<m;j++){
            if(j==c)continue;
            if(mat[r][j]==1)return false;
        }
        for(int i=0;i<n;i++){
            if(i==r)continue;
            if(mat[i][c]==1)return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(valid(i,j,n,m,mat))cnt++;
                }
            }
        }
        return cnt;
    }
};