class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mapPair;
        for (int i = 0; i < nums.size(); i++) {
            int searchValue = target - nums.at(i);
            if (mapPair.contains(searchValue)) {
                return {mapPair[searchValue], i};
            }
            mapPair[nums.at(i)] = i;
        }
        return {};
    }
};
