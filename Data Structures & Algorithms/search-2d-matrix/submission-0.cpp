class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.at(i).size(); j++) {
                if (matrix.at(i).at(j) == target) {
                    found = true;
                }
            }
        }
        return found;
    }
};
