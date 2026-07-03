class Solution {
public:
    typedef long long ll;
    typedef pair<ll,int> P;
    bool check(int mid,int n,ll k,vector<vector<vector<int>>>&adj){
        vector<ll>result(n,LLONG_MAX);
        priority_queue<P,vector<P>,greater<P>>q;
        q.push({0,0});
        result[0]=0;
        while(!q.empty()){
            ll d=q.top().first;
            int u=q.top().second;
            q.pop();
            if(result[u]<d)continue;
            
            if(d>k)return false;
            if(u==n-1)return true;
            for(auto& it:adj[u]){
                int v=it[0];
                int cost=it[1];
                if(cost<mid)continue;
                if(d+cost<result[v]){
                    result[v]=d+cost;
                    q.push({d+cost,v});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<vector<int>>> adj(n);
        int maxi=0;int mini=INT_MAX;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            if(!online[u] || !online[v])continue;
                adj[u].push_back({v,cost});
                maxi=max(maxi,cost);
                mini=min(mini,cost);
                
        }
        
        int l=mini;
        int h=maxi;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(mid,n,k,adj)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
        
    }
};