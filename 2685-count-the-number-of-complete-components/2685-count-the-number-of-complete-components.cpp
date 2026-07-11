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
    bool findd(vector<int>&temp,vector<vector<int>>&edges){
        for(const auto &it:edges){
            if(it==temp)return true;
        }
        return false;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        disjointset ds(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            ds.unionBysize(u,v);
        }
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            int par=ds.findUpar(i);
            mpp[par].push_back(i);
        }
        int cnt=mpp.size();
        for(auto it:mpp){
            int par=it.first;
            vector<int>temp=it.second;
            int m=temp.size();
            bool ok=true;
            for(int i=0;i<m && ok;i++){
                int u=temp[i];
                for(int j=i+1;j<m;j++){
                    int v=temp[j];
                    vector<int>pp={u,v};
                    vector<int>op={v,u};
                    if(!findd(pp,edges) && !findd(op,edges)){
                        cnt--;
                        ok=false;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};