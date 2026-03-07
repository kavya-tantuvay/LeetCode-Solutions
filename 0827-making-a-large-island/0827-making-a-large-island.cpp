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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int no=0;
        disjointset ds(n*n);
        int dr[4]={0,-1,0,+1};
        int dc[4]={-1,0,+1,0};
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0)continue;
                no++;
                int node=r*n+c;
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    int nnode=nr*n+nc;
                    if(nr<n&&nc<n&&nr>=0&&nc>=0 && grid[nr][nc]==1){
                        if(ds.findUpar(nnode)!=ds.findUpar(node)){
                            ds.unionBysize(node,nnode);
                        }
                    }
                }
            }
        }
        int mx=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1)continue;
                int node=r*n+c;
                set<int>comp;
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    int nnode=nr*n+nc;
                    if(nr<n&&nc<n&&nr>=0&&nc>=0 && grid[nr][nc]==1){
                        comp.insert(ds.findUpar(nnode));
                    }
                }
                int size=0;
                for(auto it:comp){
                    size+=ds.size[it];
                }
                mx=max(mx,size+1);
            }
        }
        return no==(n*n)?n*n:mx;
    }
};