class Solution {
   public:
    [[nodiscard]]
    inline constexpr bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::set<std::vector<string>> setOfStrs;

        std::sort(strs.begin(), strs.end());
        std::vector<std::vector<string>> output;
        std::map<string, int> stringToIndex;

        for (string str : strs) {
            string key = str;
            std::sort(key.begin(), key.end());
            if (stringToIndex.contains(key)) {
                output.at(stringToIndex[key]).push_back(str);

            } else {
                stringToIndex[key] = output.size();
                output.push_back({str});
            }
        }
        return output;
    };
};