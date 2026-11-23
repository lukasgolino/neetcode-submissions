class Solution {
   public:
    bool wraps(int leftValue, int rightValue) { return leftValue > rightValue; }

    bool contains(int leftValue, int rightValue, int target) {
        if (!wraps(leftValue, rightValue)) {
            std::cout << "Checking whether " << target << " in [" << leftValue << ", " << rightValue
                      << "] = " << (target >= leftValue && target <= rightValue) << "\n";
            return (target >= leftValue && target <= rightValue);
        } else {
            std::cout << "Checking whether " << target << " in [" << leftValue << ", inf) or [0,"
                      << rightValue << "] = " << (target >= leftValue || target <= rightValue)
                      << "\n";

            return (target >= leftValue || target <= rightValue);
        }
        return false;
    }

    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = std::floor(((double)(left) + (double)(right)) / 2);
            int midValue = nums.at(mid);
            if (midValue == target) return mid;

            int leftValue = nums.at(left);
            int rightValue = nums.at(right);
            if (contains(midValue, rightValue, target)) {
                // Target is somewhere on rhs
                left = mid + 1;
            } else if (contains(leftValue, midValue, target)) {
                // Target is somewhere in lhs
                right = mid - 1;
            } else {
                // Target is in neither half
                return -1;
            }
        }

        std::cout << "[" << left << ", " << right << "]\n";
        // Here the size is two, so one of them is true, or not
        if (nums.at(left) == target) {
            return left;
        } else {
            return -1;
        }
    }
};
