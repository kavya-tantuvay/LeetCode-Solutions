class Solution {
public:
    int countLargestGroup(int n) {
        int maxi=0;
        vector<int>ans(45,0);
        for(int i=1;i<=n;i++){
            int num=i;
            int s=0;
            while(num>0){
                int d=num%10;
                s+=d;
                num/=10;
            }
            ans[s]++;
            maxi=max(maxi,ans[s]);
        }
        sort(ans.begin(),ans.end(),greater<int>());
        int cnt=0,i=0;
        while(ans[i]==maxi){
            cnt++;
            i++;
        }
        return cnt;
    }
};