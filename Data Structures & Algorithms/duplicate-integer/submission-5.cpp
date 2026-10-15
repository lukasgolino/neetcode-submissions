class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int, int> map;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (map.contains(nums.at(i))) {
                return true;
            } else {
                map.insert({nums.at(i), i});
            }
        }
        return false;
    }
};