class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1) {
            return 0;
        }
        int left = 0;
        int right = 1;
        int maxProfit = 0;

        while (right < prices.size()) {
            if (prices.at(right) > prices.at(left)) {
                maxProfit = std::max(maxProfit, (prices.at(right) - prices.at(left)));
                right++;
            }
            // Else, we found a cheaper buy day
            else {
                left = right;
                right++;
            }
        }

        return maxProfit;
    }
};
