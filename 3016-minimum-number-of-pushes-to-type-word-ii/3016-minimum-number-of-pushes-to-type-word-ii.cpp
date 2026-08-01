class Solution {
public:
    int minimumPushes(string word) {
        vector<int>f(26,0);
        int ans=0;
        for(char ch:word){
             f[ch-'a']++;
        }
        sort(f.begin(),f.end(),greater<int>());
        for(int i=0;i<26;i++){
            if(f[i]==0)break;
            if(i>=0 && i<8)ans+=f[i];
            else if(i>=8 && i<16)ans+=f[i]*2;
            else if(i>=16 && i<24) ans+=f[i]*3;
            else ans+=f[i]*4;
        }
        return ans;

    }
};