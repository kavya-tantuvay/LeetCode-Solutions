class Solution {
public:
    int timer=0;
    void dfs(int node,int parent,vector<int>adj[],vector<vector<int>>&bridges,vector<int>&tin,vector<int>&low,vector<int>&vis){
        vis[node]=1;
        tin[node] = low[node] = timer++;
    
        for(auto it:adj[node]){
            if(it==parent)continue;
            else if(!vis[it]){
                dfs(it,node,adj,bridges,tin,low,vis);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>>bridges;
        vector<int>vis(n,0);
        vector<int>tin(n,-1),low(n,-1);
    
        dfs(0,-1,adj,bridges,tin,low,vis);
        return bridges;
    }
};