class Solution {
   public:
    bool isPalindrome(string s) {
        std::size_t leftIndex = 0;
        std::size_t rightIndex = s.size() - 1;

        while (leftIndex < rightIndex) {
            if (!isalnum(s.at(leftIndex)) && !isalnum(s.at(rightIndex))) {
                ++leftIndex;
                --rightIndex;
                continue;
            } else if (!isalnum(s.at(leftIndex))) {
                ++leftIndex;
                continue;
            } else if (!isalnum(s.at(rightIndex))) {
                --rightIndex;
                continue;
            }

            if (toupper(s.at(leftIndex)) != toupper(s.at(rightIndex))) {
                return false;
            } else {
                ++leftIndex;
                --rightIndex;
            }
        }
        return true;
    };
};
