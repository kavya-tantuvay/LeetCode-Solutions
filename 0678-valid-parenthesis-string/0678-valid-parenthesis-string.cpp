class Solution {
public:
    // bool solve(string s,int ind,int cnt){
    //     if(cnt<0)return false;
    //     if(ind==s.size()){
    //         return cnt==0;
    //     }
    //     if(s[ind]=='(')return solve(s,ind+1,cnt+1);
    //     if(s[ind]==')')return solve(s,ind+1,cnt-1);
    //     return(solve(s,ind+1,cnt+1)||solve(s,ind+1,cnt-1)||solve(s,ind+1,cnt));
    // }
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                min++;max++;
            }
            else if(s[i]==')'){
                min--;max--;
            }
            else{
                min--;max++;
            }
            if(min<0)min=0;
            if(max<0)return false;
        }
        return min==0;
    }
};