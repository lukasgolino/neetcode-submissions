class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<double, double>> cars;  // position, speed

        for (std::size_t i = 0; i < position.size(); i++) {
            cars.push_back({position.at(i), speed.at(i)});
        }

        std::sort(cars.begin(), cars.end(),
                  [](std::pair<double, double> a, std::pair<double, double> b) {
                      return a.first < b.first;
                  });

        std::vector<double> timeOfArrival(position.size(), 0);

        for (std::size_t i = 0; i < cars.size(); i++) {
            timeOfArrival.at(i) = (target - cars.at(i).first) / cars.at(i).second;
        }

        int numFleets = 1;
        double maxArrivalTime = *(timeOfArrival.end() - 1);
        for (int i = timeOfArrival.size() - 2; i >= 0; i--) {
            if (timeOfArrival.at(i) > maxArrivalTime) {
                numFleets++;
                maxArrivalTime = timeOfArrival.at(i);
            }
        }
        return numFleets;
    }
};
