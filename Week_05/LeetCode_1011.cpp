
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int res = 0;
        int left = 0, right = 0;
        int size = weights.size();
        
        for (int i = 0;i < size;i++) {
            right += weights[i];
            left = max(left, weights[i]);
        }
        res = right;
        
        while (left <= right) {
            int mid = (left + right) >> 1;
            int day = 0;
            int temp = 0;
            for (int i = 0;i < size;i++) {
                temp += weights[i];
                if (temp > mid) {
                    day++;
                    temp = weights[i];
                }
            }
            day++;
            
            if (day > D) {
                left = mid + 1;
            }
            if (day <= D) {
                right = mid - 1;
                res = min(res, mid);
            }
        }
        return res;
    }
};