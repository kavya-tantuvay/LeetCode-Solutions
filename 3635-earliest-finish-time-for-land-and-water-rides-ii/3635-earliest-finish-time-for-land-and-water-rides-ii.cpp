class Solution {
public:
    int solve(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration){
        int f1=INT_MAX;
        int f2=f1;
        int n=landStartTime.size();
        int m=waterStartTime.size();
        for(int i=0;i<n;i++){
            f1=min(f1,landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++){
            f2=min(f2,max(waterStartTime[i],f1)+waterDuration[i]);
        }
        return f2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int lw=solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int wl=solve(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(lw,wl);
    }
};