#include <iostream>
#include <exception>
using namespace std;

class myexc : public exception {
public:
    const char* what() const noexcept override { // Ensure correct signature with noexcept
        return "Division by zero is not allowed!";
    }
};

int main() {
    int a, b;
    cout << "Enter 2 numbers to divide:" << endl;
    cin >> a >> b;

    try {
        if (b == 0)
            throw myexc(); // Throw an object of myexc
        else
            cout << "Result: " << a / b << endl;
    }
    catch (const myexc &e) { // Catch by reference
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
