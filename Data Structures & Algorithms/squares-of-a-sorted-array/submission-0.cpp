class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares;
        for (auto num : nums) {
            squares.push_back(num * num);
        }

        std::sort(squares.begin(), squares.end());

        return squares;
    }
};