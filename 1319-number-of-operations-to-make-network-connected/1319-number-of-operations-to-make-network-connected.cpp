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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if (m<n-1)return -1;
        int cnt=0;
        disjointset ds(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            ds.unionBysize(u,v);
        }
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)cnt++;
        }
        return cnt-1;
    }
};