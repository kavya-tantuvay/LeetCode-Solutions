class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int dist=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(colors[i]!=colors[j])dist=max(dist,abs(i-j));
            }
        }
        return dist;
    }
};