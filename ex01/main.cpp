#include "RPN.hpp"

int main(int argc, char* argv[]) {
    std::string input = argv[1];
    std::stack<int> stack;
    std::stringstream ss(input);
    std::string token;
    parsing(argc, argv);

    while (std::getline(ss, token, ' ')) {
        if (isNumber(token)) {
            stack.push(std::stoi(token));
        } else {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            switch (token[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/':
                    if (b == 0) {
                       std::cout << "Error: division by zero" << std::endl;
                       return (1);
                    }
                    stack.push(a / b);
                    break;
                case '%': stack.push(a % b); break;
                default:
                {
                    std::cout << "Error: invalid operator" << std::endl;
                    return (1);
                }
            }
        }
    }
    if (stack.size() != 1) {
        std::cout << "Error: invalid input" << std::endl;
        return (1);
    }
    std::cout << stack.top() << std::endl;
    return (0);
}
