class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> set;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (set.contains(nums.at(i))) {
                return true;
            } else {
                set.insert({nums.at(i)});
            }
        }
        return false;
    }
};