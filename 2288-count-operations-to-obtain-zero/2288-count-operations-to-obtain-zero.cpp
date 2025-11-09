class Solution {
public:
    void count(int &a,int &b,int &cnt){
        if(a==0 || b==0)return;
        cnt++;
        if(a>=b)a-=b;
        else b-=a;
        count(a,b,cnt);
    }
    int countOperations(int num1, int num2) {
        int cnt=0;
        count(num1,num2,cnt);
        return cnt;
    }
};