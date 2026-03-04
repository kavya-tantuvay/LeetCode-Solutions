class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m=flights.size();
        vector<pair<int,int>>adjlist[n];
        for(int i=0;i<m;i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adjlist[u].push_back({v,w});
        }
        queue<tuple<int,int,int>>q;
        q.push({0,src,0});
        vector<int>dist(n,1e9);
        dist[src]=0;
      
        while(!q.empty()){
            auto [stops,u,cost]=q.front();
        
            q.pop();
            if(stops > k) continue;
           
            for(auto it : adjlist[u]){
                int v=it.first;
                int wt=it.second;
                if(cost+wt<dist[v] && stops<=k){
                    dist[v]=cost+wt;
                    q.push({stops+1,v,dist[v]});
                }
            }
           
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};