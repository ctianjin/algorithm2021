class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, result = 0;

        if (n == 1)
            return 1;

        for (int i = 1;i < n;i++) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};