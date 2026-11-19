class Solution {
public:
    int findMin(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        return nums.at(0);
    }
};
