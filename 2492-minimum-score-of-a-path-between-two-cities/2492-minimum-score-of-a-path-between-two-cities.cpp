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
        disjointset ds(n+1);
        for (auto &it : roads) {
            ds.unionBysize(it[0], it[1]);
        }

        int ans = INT_MAX;
        int root = ds.findUpar(1);

        for (auto &it : roads) {
            if (ds.findUpar(it[0]) == root)
                ans = min(ans, it[2]);
        }
        return ans;
    }      
};