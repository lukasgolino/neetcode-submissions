class MinStack {
   public:
    void print() {
        for (auto num : data_) {
            // std::cout << num << ",";
        }
        // std::cout << std::endl;
    }

    MinStack() {}

    void push(int val) {
        print();
        data_.push_back(val);
        print();
    }

    void pop() {
        print();
        data_.pop_back();
        print();
    }

    int top() {
        print();
        return data_.at(data_.size() - 1);
    }

    int getMin() {
        std::vector<int> myCopy(data_.size());
        std::copy(data_.begin(), data_.end(), myCopy.begin());
        std::sort(myCopy.begin(), myCopy.end());
        return myCopy.at(0);
    }

   private:
    std::deque<int> data_;
};
