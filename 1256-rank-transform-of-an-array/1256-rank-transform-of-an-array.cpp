using pp=pair<int,int>;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()<=0)return {};
      
        int n=arr.size();
        priority_queue<pp,vector<pp>,greater<pp>>minh;
        for(int i=0;i<n;i++){
            minh.push({arr[i],i});
        }
        int rank=0;
        int prev=INT_MAX;
        for(int i=0;i<n;i++){
            auto it=minh.top();
            minh.pop();
            if(it.first!=prev){
                rank++;
            }
            prev=it.first;
            arr[it.second]=rank;
        }
        return arr;
    }
};