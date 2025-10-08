class Solution {
public:
    int required(int spell,vector<int>&nums,long long k){
        int low=0;
        int high=nums.size()-1;
        int cnt=0;
        while(low<=high){
            int mid=low + (high - low) / 2;
            long long req=(long long)spell*(long long)nums[mid];
            if(req>=k){
                high=mid-1;
                cnt=nums.size()-mid;
            }
            else{
                low=mid+1;
            }
        }
        return cnt;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            int cnt=required(spells[i],potions,success);
            ans.push_back(cnt);
        }
        return ans;
    }
};