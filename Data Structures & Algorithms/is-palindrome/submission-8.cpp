
class Solution {
   public:
    bool isPalindrome(string s) {
        string clean = "";
        for (auto letter : s) {
            if (std::isalnum(letter)) {
                clean+=(toupper(letter));
            }
        }
        return (clean == string(clean.rbegin(), clean.rend()));
    }
};
