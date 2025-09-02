class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n=hand.size();
        if(n%k!=0)return false;
        unordered_map<int,int>count;
        for(int i:hand){
            count[i]++;
        }
        priority_queue<int,vector<int>,greater<int>>minh;
        for(auto it:count){
            minh.push(it.first);
        }
        while(!minh.empty()){
            int first=minh.top();
            for(int i=0;i<k;i++){
                int card=first+i;
                if(count[card]==0)return false;
                count[card]--;
                if(count[card]==0){
                    if(card!=minh.top())return false;
                    minh.pop();
                }
            }
        }
        return true;
    }
};