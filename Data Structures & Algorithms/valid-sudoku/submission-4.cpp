class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> rows(9);
        std::vector<std::unordered_set<char>> cols(9);
        std::vector<std::unordered_set<char>> minis(9);
        for (std::size_t i = 0; i < 9; i++) {
            for (std::size_t j = 0; j < 9; j++) {
                // Here push back each event exactly 3 times to the correct set.
                // std::cout << "(" << i << "," << j << ")->" << index << "\n";
                auto character = board.at(i).at(j);
                if (character == '.') {
                    continue;
                }
                int index = floor(j/3) + 3*floor(i/3);
                if (rows.at(i).contains(character) || cols.at(j).contains(character) ||
                    minis.at(index).contains(character)) {
                    return false;
                } else {
                    rows.at(i).insert(character);
                    cols.at(j).insert(character);
                    minis.at(index).insert(character);
                }
            }
        }
        return true;
    }
};