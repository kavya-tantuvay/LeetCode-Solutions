class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()<=0)return {};
        vector<int>ans(arr);
        int n=arr.size();
        sort(ans.begin(),ans.end());
        unordered_map<int,int>rank;
        rank[ans[0]]=1;
        for(int i=1;i<n;i++){
            if(ans[i]==ans[i-1]){
                rank[ans[i]]=rank[ans[i-1]];
            }
            else rank[ans[i]]=rank[ans[i-1]]+1;
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(rank[arr[i]]);
        }
        return res;
    }
};