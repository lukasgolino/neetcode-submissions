class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) {
            return s.size();
        }
        std::unordered_set<char> seen;
        int left = 0;
        int right = 1;
        int longestString = 1;
        int currentLongestString = 1;
        seen.insert(s[left]);

        while (right < s.size()) {
            // If this one is not seen we shift right another index, and iterate everything.
            if (!seen.contains(s[right])) {
                seen.insert(s[right]);
                right++;
                currentLongestString++;
                longestString = std::max(longestString, currentLongestString);
            } else {
                // Seen this one, so that's the limit of our current string, remove left until we
                // remove the previously seen char.
                seen.erase(s[left]);
                currentLongestString--;
                left++;
            }
        }
        return longestString;
    }
};
