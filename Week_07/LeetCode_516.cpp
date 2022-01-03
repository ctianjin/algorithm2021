class Solution {
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<int> buf(n, 0);
        vector<vector<int>> state(n, buf);
        int max_len = 1;
        //initial
        for (int i = 0; i < n; i++)
            state[i][i] = 1;

        for (int len = 1; len < n; len++)
        {
            for (int i = 0; i < n - len; i++)
            {
                int j = i + len;
                if (s[i] == s[j])
                    state[i][j] = state[i + 1][j - 1] + 2;
                else
                    state[i][j] = max(state[i][j - 1], state[i + 1][j]);

                if (state[i][j] > max_len)
                    max_len = state[i][j];
            }
        }
        return max_len;
    }
};