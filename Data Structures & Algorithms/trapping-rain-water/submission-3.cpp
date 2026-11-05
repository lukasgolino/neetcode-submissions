class Solution {
   public:
    int trap(vector<int>& height) {
        // If there are only 2 heights in the map, you have a mountain, there is no basin for water
        // to be held in.
        if (height.size() < 3) {
            return 0;
        }

        std::size_t left = 0;
        std::size_t right = height.size() - 1;

        // Current heighest bounding box to the left and right
        int leftMax = height.at(left);
        int rightMax = height.at(right);

        int totalWater = 0;

        while (left < right) {
            // Since leftMax is the lower of the two, it will "overflow" before the right, therefore
            // I am bounded to the left for this box.
            if (leftMax < rightMax) {
                left++;
                leftMax = std::max(leftMax, height.at(left));
                totalWater += leftMax - height.at(left);
            }
            // Here, my current pit will be bounded by the right, therefore add the difference
            // between those.
            else {
                right--;
                rightMax = std::max(rightMax, height.at(right));
                totalWater += rightMax - height.at(right);
            }
        }
        return totalWater;
    }
};
