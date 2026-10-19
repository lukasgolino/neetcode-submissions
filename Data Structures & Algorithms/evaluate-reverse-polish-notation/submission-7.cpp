class Solution {
   public:
    bool isOperator(string token) {
        if (token.size() > 1) {
            return false;
        }
        char tokenAsChar = token[0];
        if (tokenAsChar == '+' || tokenAsChar == '-' || tokenAsChar == '*' || tokenAsChar == '/') {
            return true;
        } else {
            return false;
        }
    }
    int performOperation(int a, int b, string operation) {
        char operationAsChar = operation[0];
        // std::cout << "performing " << a << operation << b << " = ";
        switch (operationAsChar) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                return a;
        }
    }
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbers;
        std::stack<string> operators;
        for (string str : tokens) {
            // std::cout << "token = " << str << std::endl;
            if (isOperator(str)) {
                operators.push(str);
            } else {
                numbers.push(std::stoi(str));
            }

            if (!operators.empty() && numbers.size() > 1) {
                // Calulcate
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                string currentOperator = operators.top();
                operators.pop();
                numbers.push(performOperation(a, b, currentOperator));
                // std::cout << numbers.top() << std::endl;
            }
        }
        return numbers.top();
    }
};
