class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;

        while (leftIndex <= rightIndex) {
            int centreIndex = leftIndex + ((rightIndex - leftIndex) / 2);
            if (nums.at(centreIndex) < target) {
                leftIndex = centreIndex + 1;
            } else if (nums.at(centreIndex) > target) {
                rightIndex = centreIndex - 1;
            } else {
                return centreIndex;
            }
        }
        return -1;
    }
};
