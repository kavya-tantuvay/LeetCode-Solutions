class Solution {
public:
    int ind(string s,char c){
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==c)return i;
        }
        return 0;
    }
    int firstUniqChar(string s) {
        map<char,int>mpp;
        for(char ch:s){
            mpp[ch]++;
        }
        int mini=-1;
        for(auto it:mpp){
            if(it.second==1){
                int i=ind(s,it.first);
                mini=i;
                break;
            }
        }
        for(auto it:mpp){
            if(it.second==1){
                int i=ind(s,it.first);
                mini=min(mini,i);
            }
        }
        return mini!=-1?mini:-1;
    }
};