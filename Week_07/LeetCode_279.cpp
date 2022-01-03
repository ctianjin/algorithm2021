class Solution {
public:
    int numSquares(int n){
        int max_num = static_cast<int> (sqrt(n) + 0.000001);
        vector<int> square(max_num + 1);
        for (size_t i = 0; i <= max_num; i++) {
            square[i] = i * i;
        }
        vector<int> dp;
        dp.assign(n + 1, 0);
        for (int i = static_cast<int>(square.size()) - 1; i > 0;i--) {
            dp[square[i]] = 1;
            int max_check = n - square[i];
            for (int j = 0; j <= max_check; j++) {
                if (dp[j]) {
                    if (!dp[j + square[i]]) {
                        dp[j + square[i]] = dp[j] + 1;
                    }
                    else {
                        dp[j + square[i]] = min(dp[j] + 1, dp[j + square[i]]);
                    }
                }
            }
        }
        return dp[n];
    }
};