class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int result = 0;
        int max_length = 0; //最大递增子序列长度
        vector<int>len(nums.size(), 1); //以nums[i]为结尾的递增子序列中元素的个数
        vector<int>times(nums.size(), 1); //以nums[i]为结尾的递增子序列出现的次数

        if (nums.size() < 2)
            return nums.size();

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (len[j] == len[i])
                        times[i] = times[j];
                    if (len[j] + 1 == len[i])
                        times[i] += times[j];
                    len[i] = max(len[i], len[j] + 1);
                }
            }
            max_length = (max_length > len[i] ? max_length : len[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (max_length == len[i])
                result += times[i];
        }
        return result;
    }
};