class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> mySet(nums.begin(), nums.end());
        return mySet.size() != nums.size();
        
    }
};