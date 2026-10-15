class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::int32_t nonZeroProduct = 1;
        bool zero = false;
        for (auto num : nums) {
            if (num) {
                nonZeroProduct *= num;
            } else if (!zero){
                zero = true;
            }
            else
            {
                return std::vector<int>(nums.size());
            }
        }

        std::vector<int> output;
        for (std::size_t i = 0; i < nums.size(); i++) {
            if (nums.at(i) != 0 && !zero) {
                output.push_back(nonZeroProduct / nums.at(i));
            } else if (nums.at(i) != 0 && zero) {
                output.push_back(0);
            } else {
                output.push_back(nonZeroProduct);
            }
        }
        return output;
    }
};
