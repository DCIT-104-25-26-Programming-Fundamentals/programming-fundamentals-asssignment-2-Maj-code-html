#include <iostream>
using namespace std;

void printSingleTable(int number) {
    cout << "Multiplication Table for " << number << ":\n";
    for (int i = 1; i <= 12; i++) {
        cout << number << " x " << i << " = " << number * i << endl;
    }
}

void printTablesUpToN(int n) {
    for (int table = 1; table <= n; table++) {
        cout << "\nMultiplication Table for " << table << ":\n";
        for (int i = 1; i <= 12; i++) {
            cout << table << " x " << i << " = " << table * i << endl;
        }
        if (table < n) {
            cout << "---------------------------\n";
        }
    }
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Number must be a positive integer." << endl;
        return 0;
    }

    printSingleTable(n);
    printTablesUpToN(n);

    return 0;
}

