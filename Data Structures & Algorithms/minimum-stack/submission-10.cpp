class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        data_.push(val);
        // auto pushee = minData_.empty() ? val : std::min(minData_.top(), val);
        minData_.push( minData_.empty() ? val : std::min(minData_.top(), val) );
    }

    void pop() {
        data_.pop();
        minData_.pop();
    }

    int top() { return data_.top(); }

    int getMin() { return minData_.top(); }

   private:
    std::stack<int> data_;
    std::stack<int> minData_;
};
