class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int n=nums[i];
            int s=0;
            while(n>0){
                int d=n%10;
                s+=d;
                n/=10;
            }
            if(s==i)return i;
        }
        return -1;
    }
};