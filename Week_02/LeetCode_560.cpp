class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, res = 0;
        unordered_map<int, int> sum_map;
        sum_map[0] = 1;

        for (int i = 0;i < n;i++) {
            sum += nums[i];
            res += sum_map[sum - k];
            sum_map[sum] ++;
        }
        return res;
    }
};