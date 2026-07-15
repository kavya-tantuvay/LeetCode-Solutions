class Solution {
public:
    int gcd(int a,int b){
        while(a>0 && b>0){
            if(a>b)a=a%b;
            else b=b%a;
        }
        if(a==0)return b;
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = 1LL * n * n;         
        long long sumEven = 1LL * n * (n + 1);   
        return gcd(sumOdd, sumEven);
      
    }
};