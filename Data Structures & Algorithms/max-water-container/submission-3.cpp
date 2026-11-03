class Solution {
   public:
    int maxArea(vector<int>& heights) {
        std::vector<std::pair<int, int>> bars;  // Height, index

        for (int i = 0; i < heights.size(); i++) {
            bars.push_back({heights.at(i), i});
        }

        int maxArea = 0;
        int left = 0;
        int right = bars.size() - 1;
        while (left < right) {
            auto distance = abs(bars.at(left).second - bars.at(right).second);
            auto shortest = min(bars.at(left).first, bars.at(right).first);
            auto area = distance * shortest;
            if (area > maxArea) {
                maxArea = area;
            }
            bool leftIsShortest = bars.at(left).first < bars.at(right).first;
            if (leftIsShortest) {
                left++;
                continue;
            } else {
                right--;
                continue;
            }
        }

        return maxArea;
    }
};
