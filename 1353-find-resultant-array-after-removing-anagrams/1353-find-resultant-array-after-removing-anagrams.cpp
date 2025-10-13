class Solution {
public:
    bool anagram(string a,string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prevKey = "";
        for (const string &w : words) {
            string key = w;          
            sort(key.begin(), key.end());
            if (ans.empty() || key != prevKey) {
                ans.push_back(w);
                prevKey = key;
            }
        }
        return ans;
    }
};