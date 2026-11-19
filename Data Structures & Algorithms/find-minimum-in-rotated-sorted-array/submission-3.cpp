class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        if (nums.at(left) < nums.at(right)) {
            return nums.at(left);
        }

        while (left < right - 1) {
            int centreIndex = std::floor((double)(left) + (double)(right)) / 2;
            int centreValue = nums.at(centreIndex);

            if (centreValue > nums.at(right)) {
                left = centreIndex;
            } else if (centreValue < nums.at(right)) {
                right = centreIndex;
            }
        }
        return nums.at(right);
    }
};
