#include "RPN.hpp"

int main(int argc, char* argv[]) {
    std::stack<int> stack;
    int b, a;
    parsing(argc, argv);
    for (int i = 0; argv[1][i]; i++) {
        if (isdigit(argv[1][i]) || argv[1][i] == ' ') {
            if (isdigit(argv[1][i]))
                stack.push(argv[1][i] - '0');
        } 
        else if (stack.size() > 1)
        {
            b = stack.top();
            stack.pop();
            a = stack.top();
            stack.pop();
            switch (argv[1][i]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/':
                    if (b == 0) {
                       std::cerr << "Error: division by zero" << std::endl;
                       return (1);
                    }
                    stack.push(a / b);
                    break;
                case '%': stack.push(a % b); break;
                default:
                {
                    std::cerr << "Error: invalid operator" << std::endl;
                    return (1);
                }
            }
        }
        else
        {
            std::cerr << "Error: invalid input" << std::endl;
            return (1);
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Error: invalid input" << std::endl;
        return (1);
    }
    std::cout << stack.top() << std::endl;
    return (0);
}
