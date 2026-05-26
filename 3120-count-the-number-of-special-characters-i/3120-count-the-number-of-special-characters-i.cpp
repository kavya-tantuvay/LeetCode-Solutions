class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mpp;
        int r=0;
        for(char c : word){
            mpp[c]++;
        }
        for(auto it :mpp ){
            if(mpp.find(it.first-32)!=mpp.end())r++;
        }
        return r;
    }
};