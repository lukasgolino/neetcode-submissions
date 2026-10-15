class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::set<int> mySet;
        // for(std::size_t i=0; i<nums.size(); i++)
        for(auto value : nums)
        {
            if(!mySet.contains(value))
            {
                mySet.insert(value);
            }
            else
            {
                mySet.erase(value);
            }
        }
        return *mySet.begin();
    }
};
