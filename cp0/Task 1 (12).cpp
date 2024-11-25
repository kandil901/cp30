#include <iostream>

using namespace std;

double divide(double numerator, double denominator) {
    if (denominator == 0) throw "Error: Division by 0 is not allowed.";
    return numerator / denominator;
}

int main() {
    double num, denom;
    cout << "Enter the numerator: ";
    cin >> num;
    cout << "Enter the denominator: ";
    cin >> denom;

    try {
        double result = divide(num, denom);
        cout << "Result: " << result << endl;
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}
