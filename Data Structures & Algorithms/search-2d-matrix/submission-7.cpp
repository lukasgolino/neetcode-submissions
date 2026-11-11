class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // For result
        bool found = false;
        int numRows = matrix.size();
        int numCols = matrix.at(0).size();

        int row = 0;
        int value = matrix.at(row).at(0);

        while (row + 1 < numRows && matrix.at(row + 1).at(0) <= target) {
            row++;
        }

        std::cout << "searching for " << target << " gives row = " << row;

        for (int i = 0; i < numCols; i++) {
            if (matrix.at(row).at(i) == target) {
                found = true;
            }
        }

        return found;
    }
};
