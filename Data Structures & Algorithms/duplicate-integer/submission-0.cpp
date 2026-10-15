class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        for (std::size_t i = 0; i < nums.size(); i++) {
            for (std::size_t j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                if (nums.at(i) == nums.at(j)) return true;
            }
        }
        return false;
    }
};