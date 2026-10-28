class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        while (numbers.at(start) == 0) {
            start++;
        }

        start = std::max(start-2, 0);

        for (int i = start; i < numbers.size(); i++) {
            for (int j = start; j < numbers.size(); j++) {
                if (numbers.at(i) + numbers.at(j) == target && i != j) {
                    return {i + 1, j + 1};
                }
            }
        }
        return {0, 0};
    }
};
