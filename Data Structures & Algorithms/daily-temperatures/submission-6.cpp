class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<std::pair<int, int>> pairStack;  // temp, index

        pairStack.push({temperatures.at(0), 0});
        for (std::size_t i = 1; i < temperatures.size(); ++i) {
            // std::cout << "checking day " << i << std::endl;
            while (!pairStack.empty() && temperatures.at(i) > pairStack.top().first) {
                result.at(pairStack.top().second) = (i - pairStack.top().second);
                pairStack.pop();
            }
            pairStack.push({temperatures.at(i), i});
        }
        return result;
    }
};
