class Solution {
public:
    bool anagram(string a,string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n=words.size();
        int prev=0;
        int cur=1;
        ans.push_back(words[0]);
        while(cur<n){
            if(anagram(words[cur],words[prev])){
                cur++;
            }
            else{
                ans.push_back(words[cur]);
                prev=cur;
                cur++;
            }
        }
        return ans;

    }
};