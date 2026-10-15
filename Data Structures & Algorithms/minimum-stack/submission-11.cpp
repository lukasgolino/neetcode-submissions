class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        data_.push({val, data_.empty() ? val : std::min(data_.top().second, val)});
    }

    void pop() {
        data_.pop();
    }

    int top() { return data_.top().first; }

    int getMin() { return data_.top().second; }

   private:
    std::stack<std::pair<int,int>> data_;
};
