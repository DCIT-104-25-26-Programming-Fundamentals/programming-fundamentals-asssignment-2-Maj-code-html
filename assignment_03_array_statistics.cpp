#include <iostream>
using namespace std;

int getSum(int numbers[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += numbers[i];
    }
    return total;
}

double getAverage(int numbers[], int n) {
    int total = getSum(numbers, n);
    return static_cast<double>(total) / n;
}

int getMax(int numbers[], int n) {
    int maximum = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    return maximum;
}

int getMin(int numbers[], int n) {
    int minimum = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    return minimum;
}

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    int numbers[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    int sum = getSum(numbers, n);
    double average = getAverage(numbers, n);
    int maximum = getMax(numbers, n);
    int minimum = getMin(numbers, n);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;
}

