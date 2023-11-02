#include <iostream>
#include <stdexcept> 

using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    cout << "-----------------------------------------Simple Calculator-----------------------------------------" << endl;

    try {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;

        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            throw invalid_argument("Invalid operation. Please use +, -, *, or /.");
        }

        cout << "Enter second number: ";
        cin >> num2;

        if (operation == '/' && num2 == 0) {
            throw runtime_error("Error: Division by zero is not allowed.");
        }

        switch (operation) {
            case '+':
                result = num1 + num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                break;
        }
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unexpected error occurred." << endl;
    }

    return 0;
}