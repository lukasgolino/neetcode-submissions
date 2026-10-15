class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (std::size_t i = 0; i < prices.size(); i++) {
            for (std::size_t j = i + 1; j < prices.size(); j++) {
                auto currentProfit = prices.at(j) - prices.at(i);
                if (currentProfit > maxProfit) {
                    maxProfit = currentProfit;
                }
            }
        }
        return maxProfit;
    }
};
