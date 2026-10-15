class Solution {
   public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            auto leftChar = s.at(left);
            auto rightChar = s.at(right);

            if (!isalnum(leftChar)) {
                left++;
                continue;
            }
            if (!isalnum(rightChar)) {
                right--;
                continue;
            }

            // both are alphanum
            if (tolower(leftChar) != tolower(rightChar)) {
                return false;
            } else {
                left++;
                right--;
                continue;
            }
        }
        return true;
    }
};
