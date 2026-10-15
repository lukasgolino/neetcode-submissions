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
        int fast = calculateSquareSum(n);
        int slow = n;
        while (fast != slow) {
            fast = calculateSquareSum(calculateSquareSum(fast));
            slow = calculateSquareSum(slow);
        }
        return fast == 1;
    }
};
