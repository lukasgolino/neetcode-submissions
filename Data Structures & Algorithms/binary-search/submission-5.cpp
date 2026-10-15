class Solution {
   public:
    int search(vector<int>& nums, int target) {
        auto vecToSet = std::set(nums.begin(), nums.end());
        if (vecToSet.contains(target)) {
            return std::distance(vecToSet.begin(), vecToSet.find(target));
        }
        else
        {
            return -1;
        }
    }
};
