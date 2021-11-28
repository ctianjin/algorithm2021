class Solution
{
public:
    int findShortestSubArray(vector<int>& nums)
    {
        int times = 0;
        int n = nums.size();
        int max_length = 0xFFFF;

        unordered_map<int, vector<int>> pos_map; // first: 元素值; second: 元素下标位置集合
        unordered_map<int, vector<int>>::iterator it;

        for (int i = 0; i < n; i++){
            pos_map[nums[i]].push_back(i);
        }

        for ( it = pos_map.begin(); it != pos_map.end(); it++){
            int current_times = it->second.size();

            if (current_times > times){
                times = it->second.size();
                max_length = it->second[current_times - 1] - it->second[0] + 1;
            }

            if (current_times == times){
                if (max_length > it->second[current_times - 1] - it->second[0] + 1)
                    max_length = it->second[current_times - 1] - it->second[0] + 1;
            }
        }
        return max_length;
    }
};