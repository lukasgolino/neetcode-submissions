class Solution {
   public:
    int calculateSquareSum(int input) {
        int sum = 0;
        std::string numberAsString = std::to_string(input);
        for (char digit : numberAsString) {
            sum += (int)(digit - '0') * (int)(digit - '0');
        }
        return sum;
    }

    bool isHappy(int n) {
        std::unordered_set<int> seenValues;
        int currentValue = n;
        int i = 0;
        while (!seenValues.contains(currentValue) && currentValue != 1) {
            seenValues.insert(currentValue);
            currentValue = calculateSquareSum(currentValue);
        }
        return currentValue == 1;
    }
};
