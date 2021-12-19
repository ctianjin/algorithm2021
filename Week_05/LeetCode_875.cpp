class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        sort(piles.begin(), piles.end());
        int len = piles.size();
        int maxi = piles[len - 1];
        int l = 1, r = maxi;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (possible(piles, H, mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
    bool possible(vector<int>& piles, int H, int mid)
    {
        int sum = 0;
        for (int i = 0;i < piles.size();i++){
            sum += piles[i] % mid == 0 ? piles[i] / mid : piles[i] / mid + 1;
        }
        return sum <= H;
    }
};
