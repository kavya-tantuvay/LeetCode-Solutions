class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>mpp(26,0);
        for(char c: sentence){
            mpp[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(mpp[i]<1)return 0;
        }
        return 1;
    }
};