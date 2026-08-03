#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0;
    }
    return a / b;
}
int calcModulus(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0;
    }
    return a % b;
}
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int choice;
    double a, b;

    do {
        cout << "\n===========================\n";
        cout << "     SIMPLE CALCULATOR\n";
        cout << "===========================\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Exponentiation\n";
        cout << "7. Quit\n";
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please select 1 to 7." << endl;
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        switch (choice) {
            case 1:
                cout << "Result: " << fixed << setprecision(2) << a << " + " << b << " = " << add(a, b) << endl;
                break;
            case 2:
                cout << "Result: " << fixed << setprecision(2) << a << " - " << b << " = " << subtract(a, b) << endl;
                break;
            case 3:
                cout << "Result: " << fixed << setprecision(2) << a << " * " << b << " = " << multiply(a, b) << endl;
                break;
            case 4:
                if (b == 0) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    cout << "Result: " << fixed << setprecision(2) << a << " / " << b << " = " << divide(a, b) << endl;
                }
                break;
            case 5:
                if (b == 0) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    cout << "Result: " << a << " % " << b << " = " << calcModulus(static_cast<int>(a), static_cast<int>(b)) << endl;
                }
                break;
            case 6:
                cout << "Result: " << a << " ^ " << static_cast<int>(b) << " = " << power(a, static_cast<int>(b)) << endl;
                break;
        }
    } while (true);

    return 0;
}

