class Solution {
   public:
    // Gets the 3x3 board. 0 being top left, then reading book-wise to 9 at bottom right.
    vector<char> get3x3(vector<vector<char>>& board, std::size_t index) {
        int iBegin = std::floor(index / 3) * 3;
        int jBegin = index % 3 * 3;
        vector<char> output;
        for (std::size_t i = iBegin; i < iBegin + 3; i++) {
            for (std::size_t j = jBegin; j < jBegin + 3; j++) {
                output.push_back(board.at(i).at(j));
            }
        }
        return output;
    };

    vector<char> getRow(vector<vector<char>>& board, std::size_t index) { return board.at(index); }

    vector<char> getCol(vector<vector<char>>& board, std::size_t index) {
        vector<char> output;
        for (std::size_t i = 0; i < board.size(); i++) {
            output.push_back(board.at(i).at(index));
        }
        return output;
    };

    // Returns whether a row, column, or 3x3 is valid
    bool isValidRow(vector<char> board) {
        std::unordered_set<char> seen;
        for (auto element : board) {
            if (element != '.' && seen.contains(element)) {
                return false;
            } else {
                seen.insert(element);
            }
        }
        return true;
    };

    // Final solution
    bool isValidSudoku(vector<vector<char>>& board) {
        for (std::size_t i = 0; i < 9; i++) {
            // if (!(isValidRow(getRow(board, i)) && isValidRow(getCol(board, i)) &&
            //       isValidRow(get3x3(board, i)))) {
            //     return false;
            // }
            if (!(isValidRow(getRow(board, i)))) {
                std::cout << "getRow " << i << " not valid \n";
                return false;
            }
            if (!(isValidRow(getCol(board, i)))) {
                std::cout << "getCol " << i << " not valid \n";
                return false;
            }
            if (!(isValidRow(get3x3(board, i)))) {
                std::cout << "get3x3 " << i << " not valid \n";
                return false;
            }
        }
        return true;
    };
};
