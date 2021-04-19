#pragma once

#include < iostream > enum class sign {
    addition,
    subtraction,
    multiplication
};

class Rational
{
    private : std :: pair < int,
    int > rational;
    sign _sign = sign :: addition;

    public : Rational(int a, int b);
    virtual ~ Rational() {}

    static int gcd(int a, int b);

    int numerator();
    int denominator();

    bool isNaN();

    Rational calculations(const Rational & lhs, const Rational & rhs, const sign & _sign);

        bool operator == (const Rational & rhs);

    Rational operator + (const Rational & rhs);
Rational operator - (const Rational & rhs);
Rational operator * (const Rational & rhs);
Rational operator / (const Rational & rhs);

operator double();
operator bool();
};