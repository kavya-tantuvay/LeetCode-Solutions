class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt=0;
        for(int i=0;i<fruits.size();i++){
              int r=0;
            for(int j=0;j<baskets.size();j++){
              
                if(baskets[j]>=fruits[i]){
                    baskets[j]=-1;
                    r=1;
                    break;
                }
            }
            if(r==0)cnt++;
        }
        return cnt;
    }
};