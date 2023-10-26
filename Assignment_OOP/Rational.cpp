// Rational Class

#include <iostream>

using namespace std;
class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational(int num = 0, int denom = 1);
    Rational(const Rational &other);
    Rational &operator=(const Rational &other);
    ~Rational();

    friend ostream &operator<<(ostream &out, const Rational &rational);
    friend istream &operator>>(istream &in, Rational &rational);

    Rational operator+(const Rational &other) const;
    Rational &operator+=(const Rational &other);
    Rational operator*(const Rational &other) const;
    Rational &operator*=(const Rational &other);

    operator float() const;
};

Rational::Rational(int num, int denom) : numerator(num), denominator(denom)
{
    if (denominator == 0)
    {
        cerr << "Error: Denominator cannot be zero." << endl;
        denominator = 1;
    }
}

Rational::Rational(const Rational &other) : numerator(other.numerator), denominator(other.denominator) {}

Rational &Rational::operator=(const Rational &other)
{
    if (this != &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

Rational::~Rational() {}

ostream &operator<<(ostream &out, const Rational &rational)
{
    out << rational.numerator;
    if (rational.denominator != 1)
        out << "/" << rational.denominator;
    return out;
}

istream &operator>>(istream &in, Rational &rational)
{
    in >> rational.numerator;
    in.ignore(1); // Ignore the '/'
    in >> rational.denominator;
    return in;
}

Rational Rational::operator+(const Rational &other) const
{
    int resultNum = (numerator * other.denominator) + (other.numerator * denominator);
    int resultDenom = denominator * other.denominator;
    return Rational(resultNum, resultDenom);
}

Rational &Rational::operator+=(const Rational &other)
{
    *this = *this + other;
    return *this;
}

Rational Rational::operator*(const Rational &other) const
{
    int resultNum = numerator * other.numerator;
    int resultDenom = denominator * other.denominator;
    return Rational(resultNum, resultDenom);
}

Rational &Rational::operator*=(const Rational &other)
{
    *this = *this * other;
    return *this;
}

Rational::operator float() const
{
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

int main()
{
    Rational r1(2, 3);
    Rational r2(3, 4);

    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;

    Rational r3 = r1 + r2;
    cout << "r1 + r2: " << r3 << endl;

    Rational r4 = r1 * r2;
    cout << "r1 * r2: " << r4 << endl;

    float r1AsFloat = static_cast<float>(r1);
    cout << "r1 as float: " << r1AsFloat << endl;

    return 0;
}
