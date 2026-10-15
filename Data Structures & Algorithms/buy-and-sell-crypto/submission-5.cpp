class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (std::size_t i = 0; i < prices.size()-1; i++) {
            auto maxRight = std::max_element(prices.begin() + i, prices.end());
            auto currentMaxProfit = *maxRight - prices.at(i);
            if (currentMaxProfit > maxProfit) {
                maxProfit = currentMaxProfit;
            }
        }
        return maxProfit;
    };
};
