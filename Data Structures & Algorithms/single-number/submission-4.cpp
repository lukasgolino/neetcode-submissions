class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        std::unordered_set<int> mySet;
        for (int value : nums) {
            if (!mySet.contains(value)) {
                mySet.insert(value);
            } else {
                mySet.erase(value);
            }
        }
        return *mySet.begin();
    }
};
