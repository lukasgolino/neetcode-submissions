class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (std::size_t i = 0; i < prices.size(); i++) {
            std::vector<int> newVec(prices.begin() + i, prices.end()++);
            std::sort(newVec.begin(), newVec.end());
            auto currentMaxProfit = *(newVec.end() - 1) - prices.at(i);
            if (currentMaxProfit > maxProfit) {
                maxProfit = currentMaxProfit;
            }
        }
        return maxProfit;
    };
};
