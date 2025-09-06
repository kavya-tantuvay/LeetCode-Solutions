class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        int ans;
        sort(boxTypes.begin(),boxTypes.end(),comp);
        for(int i=0;i<n;i++){
            if(boxTypes[i][0]<=truckSize){
                truckSize-=boxTypes[i][0];
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
            }
            else{
                ans+=truckSize*boxTypes[i][1];
                break;
            }
        }
        return ans;
    }
};