#include <iostream>
using namespace std;

void printFibonacciTerms(int n) {
    if (n <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }

    int a = 0, b = 1;
    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

bool isFibonacciNumber(int number) {
    if (number < 0) {
        return false;
    }

    if (number == 0 || number == 1) {
        return true;
    }

    int a = 0, b = 1;
    while (b < number) {
        int next = a + b;
        a = b;
        b = next;
    }

    return b == number;
}

int main() {
    int n, number;

    cout << "How many terms? ";
    cin >> n;
    printFibonacciTerms(n);

    cout << "Enter a number to check: ";
    cin >> number;

    if (isFibonacciNumber(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}

