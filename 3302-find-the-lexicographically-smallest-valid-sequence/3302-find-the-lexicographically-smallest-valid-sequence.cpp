class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<int>ans;
        vector<int>suffix(n,0);
        int i=n-1;
        int j=m-1;
        int cnt=0;
        while(i>=0){
            if(j>+0 && word1[i]==word2[j]){
                cnt++;
                j--;
            }
            suffix[i]=cnt;
            i--;
        }
        bool power=true;
        i=0;j=0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(power==true && i+1<n && suffix[i+1]>=m-j-1) {
                    ans.push_back(i);
                    power=false;
                    j++;
                }
            i++;
            }
        if(j==m)return ans;
        return {};
    }
};