class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counter;  // int -> frequency
        for (int num : nums) {
            counter[num]++;
        }

        std::vector<std::vector<int>> frequency(nums.size() + 1);
        for (auto it : counter) {
            frequency.at(it.second).push_back(it.first);
        }

        std::vector<int> output;
        for (auto vec = frequency.rbegin(); vec != frequency.rend(); vec++) {
            for (auto num : *vec) {
                output.push_back(num);
                if (output.size() == k) {
                    return output;
                }
            }
        }
        return output;
    }
};
