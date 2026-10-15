class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequencyCounter;  // int -> frequency
        for (int num : nums) {
            frequencyCounter[num]++;
        }
        std::vector<std::pair<int, int>> pairVector;
        for (auto it : frequencyCounter) {
            pairVector.push_back({it.second, it.first});
        }
        std::sort(pairVector.rbegin(), pairVector.rend());

        std::vector<int> output;
        for (std::size_t i = 0; i < k; i++) {
            output.push_back(pairVector.at(i).second);
        }
        return output;
    }
};
