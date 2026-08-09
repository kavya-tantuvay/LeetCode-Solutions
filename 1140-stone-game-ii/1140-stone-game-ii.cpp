class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(n + 1, vector<int>(2, 0))
        );


        for (int i = n - 1; i >= 0; i--) {
            for (int m = n; m >= 1; m--) {

             
                int aliceRes = 0;
                int sum = 0;

                for (int x = 1; x <= 2 * m && i + x <= n; x++) {
                    sum += piles[i + x - 1];

                    aliceRes = max(
                        aliceRes,
                        sum + dp[i + x][max(m, x)][0]
                    );
                }

                dp[i][m][1] = aliceRes;


               
                int bobRes = INT_MAX;

                for (int x = 1; x <= 2 * m && i + x <= n; x++) {
                    bobRes = min(
                        bobRes,
                        dp[i + x][max(m, x)][1]
                    );
                }

                dp[i][m][0] = bobRes;
            }
        }

        return dp[0][1][1];
    }
};