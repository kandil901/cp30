#include <iostream>
#include <exception>

using namespace std;

class DivisionByZero : public exception {
public:
    const char* what() const noexcept override {
        return "Custom Error: Division by 0 is not allowed.";
    }
};

double divide(double numerator, double denominator) {
    if (denominator == 0) throw DivisionByZero();
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
    catch (const DivisionByZero& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
