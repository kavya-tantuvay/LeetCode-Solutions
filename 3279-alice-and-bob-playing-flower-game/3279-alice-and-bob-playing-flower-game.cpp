class Solution {
public:
    long long flowerGame(int n, int m) {
        // 1,2,3 - odd=2,even=1  1,2- odd=1, even=1   (n+1)/2, n/2 
        long long oddn=(n+1)/2;
        long long evenn=n/2;
        long long oddm=(m+1)/2;
        long long evenm=m/2;
        return oddn*evenm + evenn*oddm;
        
    }
};