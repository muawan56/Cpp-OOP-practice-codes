// Complex Numbers

#include <iostream>

using namespace std;
class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double realPart = 0.0, double imagPart = 0.0);
    Complex(const Complex &other);
    Complex &operator=(const Complex &other);
    ~Complex();

    friend ostream &operator<<(ostream &out, const Complex &complex);

    Complex operator+(const Complex &other) const;
    Complex &operator+=(const Complex &other);

    Complex operator*(const Complex &other) const;
    Complex &operator*=(const Complex &other);
};

Complex::Complex(double realPart, double imagPart) : real(realPart), imag(imagPart) {}

Complex::Complex(const Complex &other) : real(other.real), imag(other.imag) {}

Complex &Complex::operator=(const Complex &other)
{
    if (this != &other)
    {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}

Complex::~Complex() {}

ostream &operator<<(ostream &out, const Complex &complex)
{
    if (complex.real != 0.0)
        out << complex.real;
    if (complex.imag != 0.0)
    {
        if (complex.imag > 0.0)
        {
            if (complex.real != 0.0)
                out << " + ";
            out << complex.imag << "i";
        }
        else
        {
            out << " - " << -complex.imag << "i";
        }
    }
    return out;
}

Complex Complex::operator+(const Complex &other) const
{
    double resultReal = real + other.real;
    double resultImag = imag + other.imag;
    return Complex(resultReal, resultImag);
}

Complex &Complex::operator+=(const Complex &other)
{
    *this = *this + other;
    return *this;
}

Complex Complex::operator*(const Complex &other) const
{
    double resultReal = (real * other.real) - (imag * other.imag);
    double resultImag = (real * other.imag) + (imag * other.real);
    return Complex(resultReal, resultImag);
}

Complex &Complex::operator*=(const Complex &other)
{
    *this = *this * other;
    return *this;
}

int main()
{
    Complex c1(2.5, 3.0);
    Complex c2(1.5, -2.0);

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    Complex c3 = c1 + c2;
    cout << "c1 + c2: " << c3 << endl;

    Complex c4 = c1 * c2;
    cout << "c1 * c2: " << c4 << endl;

    return 0;
}
