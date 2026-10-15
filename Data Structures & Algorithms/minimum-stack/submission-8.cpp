class MinStack {
   public:
    // void printDeque() {
    //     for (auto num : data_) {
    //         // std::cout << num << ",";
    //     }
    //     // std::cout << std::endl;
    // }

    // void printMap() {
    //     for (auto& num : orderedMap_) {
    //         std::cout << "(" << num.first << "," << num.second << "),";
    //     }
    //     std::cout << std::endl;
    // }

    MinStack() {}

    void push(int val) {
        data_.push_back(val);
        orderedMap_[val]++;
        // printDeque();
        // printMap();
    }

    void pop() {
        if (orderedMap_[data_.at(data_.size() - 1)] == 1) {
            orderedMap_.erase(data_.at(data_.size() - 1));
        } else {
            orderedMap_[data_.at(data_.size() - 1)]--;
        }
        data_.pop_back();
        // printDeque();
        // printMap();
    }

    int top() {
        // printDeque();
        // printMap();
        return data_.at(data_.size() - 1);
    }

    int getMin() {
        // printMap();
        return orderedMap_.begin()->first;
    }

   private:
    std::deque<int> data_;
    std::map<int, int> orderedMap_;  // value -> count
};
