class Solution {
public:
    void left(vector<int>&nums){
        int n=nums.size();
        int a=nums[0];
        for(int i=0;i<n-1;i++){
            nums[i]=nums[i+1];
        }
        nums[n-1]=a;
    }
    void right(vector<int>&nums){
        int n=nums.size();
        int a=nums[n-1];
        for(int i=n-1;i>=1;i--){
            nums[i]=nums[i-1];
        }
        nums[0]=a;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans=mat;
        if(k==n)return true;
        for(int i=0;i<k;i++){
            for(int j=0;j<m;j++){
                if(j%2==0){
                    left(ans[j]);
                }
                else right(ans[j]);
            }
        }
        return ans==mat;
    }
};