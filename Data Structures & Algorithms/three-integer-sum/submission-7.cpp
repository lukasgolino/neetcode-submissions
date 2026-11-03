class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());

        for (int i = 0; i < sortedNums.size() - 1; i++) {
            int leftIndex = i + 1;
            int rightIndex = sortedNums.size() - 1;
            // Skip duplicates on the first value
            if (i > 0 && sortedNums.at(i) == sortedNums.at(i - 1)) {
                continue;
            }

            while (leftIndex < rightIndex) {
                auto tripleSum =
                    sortedNums.at(i) + sortedNums.at(leftIndex) + sortedNums.at(rightIndex);

                if (tripleSum == 0) {
                    result.push_back(
                        {sortedNums.at(i), sortedNums.at(leftIndex), sortedNums.at(rightIndex)});
                    leftIndex++;
                    rightIndex--;
                    // Skip duplicates on the second value
                    while (leftIndex < rightIndex &&
                           sortedNums[leftIndex] == sortedNums[leftIndex - 1]) {
                        leftIndex++;
                    }
                } else if (tripleSum > 0) {
                    rightIndex--;
                } else {
                    leftIndex++;
                }
            }
        }
        return result;
    }
};
