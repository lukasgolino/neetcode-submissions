class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        if (nums.empty()) {
            return 0;
        }
        vector<int> vecOfLongest;
        int currentLongest = 1;
        int currentVal = nums.at(0);
        for (std::size_t i = 1; i < nums.size(); i++) {
            if (nums.at(i) == currentVal + 1) {
                currentLongest++;
                currentVal++;
            } else if (nums.at(i) == currentVal) {
                // Duplicate, ignore
            } else {
                vecOfLongest.push_back(currentLongest);
                currentLongest = 1;
                currentVal = nums.at(i);
            }
        }
        vecOfLongest.push_back(currentLongest);
        return *(std::max_element(vecOfLongest.begin(), vecOfLongest.end()));
    }
};
