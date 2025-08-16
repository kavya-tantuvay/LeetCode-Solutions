class Solution {
public:
    int maximum69Number (int num) {
        for (int p = 1000; p > 0; p /= 10) {
            if ((num / p) % 10 == 6) {
                return num + 3 * p;
            }
        }
        return num;
    }
};
