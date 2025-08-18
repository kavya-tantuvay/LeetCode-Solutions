class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums;
        for(int i:cards){
            nums.push_back((double)i);
        }
        return helper(nums);
    }
    bool helper(vector<double>& nums){
        int n=nums.size();
        if(n==1){
            if(abs(nums[0]-24.0)< 0.000001)return true;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double a=nums[i];
                double b=nums[j];
                vector<double>ops=calcops(a,b);
                vector<double>nextround;
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j)nextround.push_back(nums[k]);
                }
                for(double o:ops){
                    nextround.push_back(o);
                    if(helper(nextround))return true;
                    nextround.pop_back();
                }
            }
        }
        return false;
    }
    vector<double>calcops(double a,double b){
        vector<double>result;
        result.push_back(a+b);
        result.push_back(a-b);
        result.push_back(b-a);
        result.push_back(a/b);
        result.push_back(b/a);
        result.push_back(a*b);
        return result;
    }
};