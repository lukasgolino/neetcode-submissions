#include <algorithm>

class Solution {
   public:
    bool isPalindrome(string s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](auto& c) { return !std::isalnum(c); }),
                s.end());
        std::transform(s.begin(), s.end(), s.begin(), [](auto& c) { return ::toupper(c); });
        if (s.empty()) {
            return true;
        }
        std::size_t leftIndex = 0;
        std::size_t rightIndex = s.size() - 1;
        while (leftIndex < rightIndex) {
            if (s.at(leftIndex) != s.at(rightIndex)) {
                return false;
            } else {
                ++leftIndex;
                --rightIndex;
            }
        }
        return true;
    };
};