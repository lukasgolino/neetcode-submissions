class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int left = 0;
        int right = heights.size() - 1;
        while (left < right) {
            auto distance = abs(left - right);
            auto shortest = min(heights.at(left), heights.at(right));
            auto area = distance * shortest;
            if (area > maxArea) {
                maxArea = area;
            }
            bool leftIsShortest = heights.at(left) < heights.at(right);
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
