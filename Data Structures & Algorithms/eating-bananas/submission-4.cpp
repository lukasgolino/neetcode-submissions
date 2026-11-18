class Solution {
   public:
    int hoursToEat(vector<int>& piles, int eatingRate) {
        int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += std::ceil(piles.at(i) / (double)(eatingRate));
        }
        return sum;
    };

    int minEatingSpeed(vector<int>& piles, int h) {
        int numPiles = piles.size();
        double minPilesPerHour = numPiles / (double)(h);

        int largestPileSize = *(std::max_element(piles.begin(), piles.end()));

        int left = 1;
        int right = largestPileSize;
        int eatingSpeed = 0;

        while (left < right) {
            eatingSpeed = std::floor(((double)(left) + (double)(right)) / 2);
            if (hoursToEat(piles, eatingSpeed) > h) {
                left = eatingSpeed + 1;
            } else {
                right = eatingSpeed;
            }
        }
        return left;
    }
};
