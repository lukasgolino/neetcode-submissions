class Solution {
   public:
    int getLargestCluster(vector<int>& heights) {
        int largestCluster = 0;
        int currentClusterSize = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights.at(i) > 0) {
                currentClusterSize++;
            } else {
                largestCluster = std::max(largestCluster, currentClusterSize);
                currentClusterSize = 0;
            }
        }
        return std::max(largestCluster, currentClusterSize);
    }

    vector<int> removeTops(vector<int> heights) {
        vector<int> newheights(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            newheights.at(i) = std::max(heights.at(i) - 1, 0);
        }
        return newheights;
    }

    int largestRectangleArea(vector<int>& heights) {
        int longestCol = *(std::max_element(heights.begin(), heights.end()));
        vector<int> heightsCopy(heights.size());
        std::copy(heights.begin(), heights.end(), heightsCopy.begin());
        int stackDepth = 0;
        int biggestRectangle = 0;
        int currentRectangle = 0;
        while (getLargestCluster(heightsCopy)>1) {
            stackDepth++;
            currentRectangle = getLargestCluster(heightsCopy) * stackDepth;
            biggestRectangle = std::max(biggestRectangle, currentRectangle);
            heightsCopy = removeTops(heightsCopy);
        }

        return std::max(biggestRectangle, longestCol);
    }
};
