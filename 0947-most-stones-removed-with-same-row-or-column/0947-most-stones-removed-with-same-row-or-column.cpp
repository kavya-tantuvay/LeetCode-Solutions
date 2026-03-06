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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxr=0,maxc=0;
        for(auto it:stones){
            int r=it[0];
            int c=it[1];
            maxr=max(maxr,r);
            maxc=max(maxc,c);
        }
        disjointset ds(maxr+maxc+1);
        set<int>st;
        for(auto it:stones){
            int r=it[0];
            int c=it[1]+maxr+1;
            ds.unionBysize(r,c);
            st.insert(r);
            st.insert(c);
        }
        int ncc=0;
        for(int i:st){
            if(ds.parent[i]==i)ncc++;
        }
        return n-ncc;
    }
};