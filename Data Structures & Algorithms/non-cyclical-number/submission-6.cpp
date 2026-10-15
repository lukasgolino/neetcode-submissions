class Solution {
   public:
    int calculateSquareSum(int input) {
        std::cout << "calculating ss for " << input << std::endl;
        int sum = 0;
        std::string numberAsString = std::to_string(input);
        for (char digit : numberAsString) {
            sum += (int)(digit - '0') * (int)(digit - '0');
        }
        std::cout << "returnign " << sum << std::endl;
        return sum;
    }

    bool isHappy(int n) {
        std::unordered_set<int> seenValues;
        int currentValue = n;
        int i = 0;
        while (!seenValues.contains(currentValue) && currentValue != 1) {
            seenValues.insert(currentValue);
            currentValue = calculateSquareSum(currentValue);
            std::cout << "Seen values = ";
            for(auto value : seenValues) { std::cout << value << ",";}
            std::cout << "\n";
            i++;
            if (i > 15) {
                // break;
            }
        }
        return currentValue == 1;
    }
};
