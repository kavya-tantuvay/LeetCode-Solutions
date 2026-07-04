class disjointset{
public:
    vector<int>parent,size;
public:
    disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUpar(int node){
        if(parent[node]==node)return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBysize(int u,int v){
        int ulpu=findUpar(u);
        int ulpv=findUpar(v);
        if(ulpu==ulpv)return;
        if(size[ulpu]<size[ulpv]){
            parent[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
        }
        else{
            parent[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
        }
    }

};
class Solution {
public:
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n+1];
        vector<int>vis(n+1,0);
        vis[1]=1;
        disjointset ds(n+1);
        int maxi=0;
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int d=it[2];
            ds.unionBysize(u,v);
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
            maxi=max(maxi,d);
        }
        int ans=maxi;
        for(int i=1;i<=n;i++){
            for(auto it:adj[i]){
                int u=it.first;
                int d=it.second;
                if(!vis[i]){
                    if(ds.findUpar(u)==ds.findUpar(n))ans=min(ans,d);
                }
            }
            vis[i]=1;
        }
        return ans;
    }
};