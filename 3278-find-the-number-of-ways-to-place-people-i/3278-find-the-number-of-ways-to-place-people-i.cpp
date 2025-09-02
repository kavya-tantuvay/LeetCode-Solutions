class Solution {
public:
    bool ispair(vector<int>&a,vector<int>&b){
        return (b[0]>=a[0])&&(b[1]<=a[1]);
    }
    bool isvalid(vector<int>&a,vector<int>&b,vector<vector<int>>&points){
        int x1=a[0],x2=b[0],y1=a[1],y2=b[1];
        for(auto it:points){
            if ((it[0] == x1 && it[1] == y1) || (it[0] == x2 && it[1] == y2)) 
                continue;
            int p=it[0];
            int q=it[1];
            if((min(x1,x2)<=p && max(x1,x2)>=p)&&(min(y1,y2)<=q && max(y1,y2)>=q)){
                return false;
            }
        }
        return true;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (i == j) continue;
                if(ispair(points[i],points[j])){
                    if(isvalid(points[i],points[j],points))cnt++;
                }
            }
        }
        return cnt;
    }
};