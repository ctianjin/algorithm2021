class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        int length = nums.size() - 1;
        permuteUnique(nums, result, 0, length);
        return result;
    }

    void permuteUnique(vector<int>& nums, vector<vector<int>>& result, int begin, int end) {
        if (begin == end) {
            result.push_back(nums);
            return;
        }
        else {
            for (int i = begin; i <= end; i++) {
                if (contain(nums, begin, i)) 
                    continue;
                swap(nums, begin, i);
                permuteUnique(nums, result, begin + 1, end);
                swap(nums, begin, i);
            }
        }
    }

    bool contain(vector<int>nums, int i, int j) {
        for (int k = i; k < j; k++) {
            if (nums[j] == nums[k])
                return true;
        }
        return false;
    }

    void swap(vector<int>& nums, int i, int k) {
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
};