class Solution {
   public:
    [[nodiscard]]
    inline constexpr char getClosingBracket(const char s) {
        char out;
        switch (s) {
            case '[':
                out = ']';
                break;
            case '{':
                out = '}';
                break;
            case '(':
                out = ')';
                break;
        }
        return out;
    };

    [[nodiscard]]
    inline constexpr bool isOpenBracket(const char& s) {
        if (s == '(' || s == '{' || s == '[') {
            return true;
        }
        return false;
    };

    bool isValid(string s) {
        if (s.size() == 0) {
            return true;
        }
        if (s.size() % 2 != 0) {
            return false;
        }

        std::stack<char> stacket;
        for (auto& bracket : s) {
            if (isOpenBracket(bracket)) {
                stacket.push(bracket);
                continue;
            }
            else if (stacket.empty() && !isOpenBracket(bracket)) {
                return false;
            } 
            // Its a close bracket
            else {
                if (bracket == getClosingBracket(stacket.top())) {
                    stacket.pop();
                    continue;
                } else {
                    return false;
                }
            }
        }
        if (stacket.size() > 0) {
            return false;
        }
        return true;
    };
};
