class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, std::vector<int>> mapPair;
        for(int i=0; i<nums.size(); i++)
        {
            if(mapPair.contains(nums.at(i)))
            {
                mapPair[nums.at(i)].push_back(i);
            }
            else
            {
                mapPair[nums.at(i)]={i};
            }
        }
        for(int i=0; i<nums.size(); i++)
        {
            int searchValue = target - nums.at(i);
            if(mapPair.contains(searchValue))
            {
                auto indexVec = mapPair[searchValue];
                for(auto index : indexVec)
                {
                    if(index != i)
                    {
                        return {i,index};
                    }
                }
            }
        }
    }
};
