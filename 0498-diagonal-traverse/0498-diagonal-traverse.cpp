class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int n = matrix.size(), m = matrix[0].size();
        vector<int> result;
        unordered_map<int,vector<int>>diag;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diag[i+j].push_back(matrix[i][j]);
            }
        }
         //No. of diagonals = m+n-1
        for(int i=0;i<m+n-1;i++){
            vector<int>list=diag[i];
            if(i%2==0){
                reverse(list.begin(),list.end());
            }
            for(int i:list){
                result.push_back(i);
            }
        }

        return result;
    }
};