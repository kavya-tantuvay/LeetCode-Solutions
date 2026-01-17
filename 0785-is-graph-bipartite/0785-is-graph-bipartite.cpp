class Solution {
public:
    bool dfs(int col,int node,vector<vector<int>>&graph,vector<int>&color){
        color[node]=col;
        for(auto it:graph[node]){
            if(color[it]==-1){
                if(dfs(!col,it,graph,color)==false)return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(0,i,graph,color)==false)return false;
            }
        }
        return true;
    }
};