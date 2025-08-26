class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        long long maxd=0;
        int maxarea=0;
        for(int i=0;i<n;i++){
            int l=dimensions[i][0];
            int b=dimensions[i][1];
            long long d=l*l+b*b;
            if (d > maxd) {
                maxd = d;
                maxarea = l*b;
            } 
            else if (d == maxd) {
                maxarea = max(maxarea, l*b);
            }
        }
        return maxarea;
    }
};