class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int>ans;
        for(int i=0;i<9;i++){
            string temp="";
            for(int j=i;j<9;j++){
                temp+=s[j];
                if(j-i+1<2)continue;
                int n=stoi(temp);
                if(n>high)break;
                if(n>=low)ans.push_back(n);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};