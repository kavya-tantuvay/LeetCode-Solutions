class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int cnt=n;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n-1;i++){
            int a=intervals[i][0];
            int b=intervals[i][1];
            int c=intervals[i+1][0];
            int d=intervals[i+1][1];
            if(a>=c && b<=d){
                cnt--;
                intervals[i+1][0]=c;
                intervals[i+1][1]=d;
            }
            else if(c>=a && d<=b){
                cnt--;
                intervals[i+1][0]=a;
                intervals[i+1][1]=b;
            }
        }
        return cnt;
    }
};