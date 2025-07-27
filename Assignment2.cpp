#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;
public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Overload +
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload -
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overload *
    Complex operator*(const Complex& c) const {
        return Complex((real * c.real - imag * c.imag), (real * c.imag + imag * c.real));
    }

    // Overload >>
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload <<
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i";
        return out;
    }

    // Overload ==
    bool operator==(const Complex& c) const {
        return (real == c.real && imag == c.imag);
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "\nFirst Number: " << c1 << endl;
    cout << "Second Number: " << c2 << endl;

    cout << "\nAddition: " << sum << endl;
    cout << "Subtraction: " << diff << endl;
    cout << "Multiplication: " << prod << endl;

    if (c1 == c2)
        cout << "\nBoth complex numbers are equal.\n";
    else
        cout << "\nComplex numbers are not equal.\n";

    return 0;
}
