class Solution {
   public:
    int calculateSquareSum(int n) {
        int output = 0;

        while (n > 0) {
            int digit = n % 10;
            digit = digit * digit;
            output += digit;
            n /= 10;
        }
        return output;
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
