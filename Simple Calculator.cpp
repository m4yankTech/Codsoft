#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter an operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation." << std::endl;
            break;
    }

    return 0;
}

