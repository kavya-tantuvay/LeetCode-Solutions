class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1)return {0};
        vector<int>ans;
          int s=n/2;
        if(n%2==1){
            for(int i=0-s;i<=s;i++){
                ans.push_back(i);
            }
        }
        if(n%2==0){
            for(int i=0-s;i<=s;i++){
                if(i!=0)ans.push_back(i);
            }
        }
        return ans;

    }
};