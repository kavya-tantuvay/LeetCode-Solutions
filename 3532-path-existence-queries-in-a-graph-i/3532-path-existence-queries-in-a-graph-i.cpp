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
    bool path(int u,int v,int n,vector<int>adj[]){
        queue<int>q;
        vector<int>vis(n,0);
        q.push(u);
        vis[u]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==v)return true;
            for(int i:adj[node]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return false;
    }
    int bs(int maxi,vector<int>&nums,int i,int r){
        int l=i;
        int ans=i;
        while(l<=r){
            int mid=l+(r-l)/2;
            int t=abs(nums[mid]-nums[i]);
            if(t<=maxi){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        disjointset ds(n);
        vector<int>adj[n];
        int i=0;
        while(i<n-1){
            if(nums[i+1]-nums[i]<=maxDiff)ds.unionBysize(i,i+1);
            i++;
        }
        vector<bool>ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            auto it=queries[i];
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v))ans[i]=true;
        }
        return ans;
    }
};