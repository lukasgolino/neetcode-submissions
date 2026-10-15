#include <algorithm>

class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        std::sort(nums.begin(), nums.end());
        for (std::size_t i = 0; i < nums.size() - 1; i++) {
            if (nums.at(i + 1) == nums.at(i)) {
                return true;
            }
        }
        return false;
    }
};