class Solution {
   public:
    bool containsCluster(vector<int>& heights) {
        int clusterSize = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights.at(i) > 0) {
                clusterSize++;
            } else {
                clusterSize = 0;
            }
            if (clusterSize > 1) {
                return true;
            }
        }
        return false;
    }

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

    void printVec(vector<int> vec) {
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i) << ",";
        }
        std::cout << "\n";
    }

    int largestRectangleArea(vector<int>& heights) {
        int longestCol = *(std::max_element(heights.begin(), heights.end()));
        vector<int> heightsCopy(heights.size());
        std::copy(heights.begin(), heights.end(), heightsCopy.begin());
        int stackDepth = 0;
        int biggestRectangle = 0;
        int currentRectangle = 0;
        while (containsCluster(heightsCopy)) {
            stackDepth++;
            // std::cout << "depth = " << stackDepth << "\n";
            // std::cout << "getLargestCluster(heightsCopy) = " << getLargestCluster(heightsCopy)
                    //   << "\n";
            currentRectangle = getLargestCluster(heightsCopy) * stackDepth;
            biggestRectangle = std::max(biggestRectangle, currentRectangle);
            // std::cout << "currentRectangle = " << currentRectangle << "\n";
            // printVec(heightsCopy);
            heightsCopy = removeTops(heightsCopy);
            // printVec(heightsCopy);
        }

        return std::max(biggestRectangle, longestCol);
    }
};
