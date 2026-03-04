class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>q;
        int dr[4]={0,-1,0,+1};
        int dc[4]={-1,0,+1,0};
        vector<vector<int>>maxe(n,vector<int>(m,1e9));
        maxe[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){
            auto it=q.top();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1)return diff;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr<n && nr>=0 && nc>=0 && nc<m ){
                    int d=max(abs(heights[nr][nc]-heights[r][c]),diff);
                    
                    if(maxe[nr][nc]>d){
                        maxe[nr][nc]=d;
                        q.push({maxe[nr][nc],{nr,nc}});
                    }
                   
                }
            }
        }
        return -1;
    }
};