#include <iostream>
#include <exception>
#include <sstream>
#include <cmath>
#include <string>
#include <map>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int num, int den) {
        if (den == 0) throw invalid_argument("Invalid argument");
        else
        if (den < 0) {
            if (num < 0) {
                den = abs(den);
                num = abs(num);
            } else {
                den = abs(den);
                num = num - 2 * num;
            }
        }

        if (num == 0) den = 1;

        int commonDen = SearchCommonDenominator(abs(num), abs(den));

        numerator = num / commonDen;
        denominator = den / commonDen;
    }

    int Numerator() const { return numerator; }

    int Denominator() const { return denominator; }

private:
    int numerator, denominator;

    static int SearchCommonDenominator(int x, int y) {
        while (x > 0 && y > 0) {
            if (x > y) x %= y;
            else y %= x;
        }

        return x + y;
    }
};

bool operator == (Rational x, Rational y) {
    if ((x.Numerator() == y.Numerator()) && (x.Denominator() == y.Denominator())) return true;
    else return false;
}

Rational operator * (Rational x, Rational y) {
    return Rational((x.Numerator() * y.Numerator()), (x.Denominator() * y.Denominator()));
}

Rational operator / (Rational x, Rational y) {
    if (y.Numerator() == 0) throw domain_error("Division by zero");

    return Rational((x.Numerator() * y.Denominator()), (x.Denominator() * y.Numerator()));
}

Rational operator + (Rational x, Rational y) {
    int a = (x.Numerator() * y.Denominator()) + (y.Numerator() * x.Denominator());
    int b = x.Denominator() * y.Denominator();

    return Rational(a, b);
}

Rational operator - (Rational x, Rational y) {
    int a = (x.Numerator() * y.Denominator()) - (y.Numerator() * x.Denominator());
    int b = x.Denominator() * y.Denominator();

    return Rational(a, b);
}

istream& operator >> (istream& stream, Rational& x) {
    int a, b;
    if (stream >> a && stream.ignore(1) && stream >> b) x = { a, b };

    return stream;
}

ostream& operator << (ostream& stream, const Rational& x) {
    stream << x.Numerator() << "/" << x.Denominator();

    return stream;
}

bool operator > (Rational x, Rational y) {
    return (x.Numerator() / (double)x.Denominator()) > double(y.Numerator() / (double)y.Denominator());
}

bool operator < (Rational x, Rational y) {
    return (x.Numerator() / (double)x.Denominator()) < (y.Numerator() / (double)y.Denominator());
}

