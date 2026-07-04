class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
         int n=s.length();
        int mod=1e9+7;
        vector<int>prefix(n+1,0);
        prefix[0]=s[0]-'0';
        for(int i=0;i<s.length();i++){
            prefix[i+1]=prefix[i]+s[i]-'0';
        }
        vector<long long>power(n+1);
        power[0]=1;
        for(int i=1;i<=n;i++){
            power[i]=(power[i-1]*10)%mod;
        }
        vector<long long>x(n+1,0);
        vector<long long>zero(n+1,0);
        for(int i=0;i<n;i++){
            int num=s[i]-'0';
            if(num!=0){
                x[i+1]=(x[i]*10+num)%mod;
                zero[i+1]=zero[i]+1;
            }
            else{
                x[i+1]=x[i];
                zero[i+1]=zero[i];
            }
        }
        vector<int>res;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            long long sum= prefix[r+1]-prefix[l];
            int zc=zero[r+1]-zero[l];
            long long num=x[r+1]-(x[l]*power[zc])%mod;
            if(num<0){
                num+=mod;
            }
            res.push_back(num*(sum%mod)%mod);
        }
        return res;
        
        
    }
};