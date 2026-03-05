class Solution {
public:
    int maxi(vector<int>&arr){
        int n=arr.size();
        int maxx=arr[1];
        for(int i=1;i<n;i++){
            maxx=max(maxx,arr[i]);
        }
        return maxx==1e9?-1:maxx;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adjlist[n+1];
        int m=times.size();
        for(int i=0;i<m;i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adjlist[u].push_back({v,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        while(!q.empty()){
            int dis=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it : adjlist[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(dist[adjnode]>dis+wt){
                    dist[adjnode]=dis+wt;
                    q.push({dis+wt,adjnode});
                }
            }
        }
        return maxi(dist);
    }
};