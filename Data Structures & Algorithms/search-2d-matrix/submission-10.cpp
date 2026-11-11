class Solution {
   public:
    bool binaryFind(std::vector<int> numbers, int target) {
        int size = numbers.size();
        int index = std::floor(numbers.size() / 2);

        int left = 0;
        int right = numbers.size();
        int searchIndex = std::floor((left + right) / 2);

        while (left != right) {
            searchIndex = std::floor((left + right) / 2);
            if (numbers.at(searchIndex) == target) {
                return true;
            } else if (numbers.at(searchIndex) > target) {
                right = searchIndex;

            } else {
                left = searchIndex+1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // For result
        int numRows = matrix.size();
        int numCols = matrix.at(0).size();

        int row = 0;
        int value = matrix.at(row).at(0);

        while (row + 1 < numRows && matrix.at(row + 1).at(0) <= target) {
            row++;
        }

        return binaryFind(matrix.at(row), target);
    }
};
