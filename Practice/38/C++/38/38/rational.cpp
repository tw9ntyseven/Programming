#include "Rational.h"

Rational :: Rational(int a = 0, int b = 0)
{
    if (a < 0 && b < 0) {
        rational.first = -a;
        rational.second = -b;
    } else {
        rational.first = a;
        rational.second = b;
    }
}

int Rational :: gcd(int a, int b)
{
    if (a == 0 || b == 0) 
        return a + b;
    
    if (a < 0 || b < 0) 
        return 1;
    
    while (a != 0 && b != 0) 
        if (a > b) 
            a = a % b;
        else 
            b = b % a;

    return a + b;
}

int Rational :: numerator()
{
    return rational.first;
}

int Rational :: denominator()
{
    return rational.second;
}

bool Rational :: operator == (const Rational & rhs)
{
    if (this - > rational.second == rhs.rational.second && this - > rational.first == rhs.rational.first) 
        return true;
    
    if (this - > rational.second == 0 || rhs.rational.second == 0) 
        return false;
    
    if (this - > rational.first == 0 && rhs.rational.first == 0) 
        return true;
    
    int od = this - > rational.second * rhs.rational.second;

    int tmp_lhs = this - > rational.first * od / this - > rational.second;
    int tmp_rhs = rhs.rational.first * od / rhs.rational.second;

    return tmp_lhs == tmp_rhs;
}

Rational Rational :: calculations(const Rational & lhs, const Rational & rhs, const sign & _sign)
        {
            int numerator;
            int denominator = 1;

            switch (_sign) {
                case sign :: addition:
                    denominator = lhs.rational.second * rhs.rational.second;

                    int tmp_lhs;
                    int tmp_rhs;

                    tmp_lhs = rational.first * denominator / lhs.rational.second;
                    tmp_rhs = rhs.rational.first * denominator / rhs.rational.second;

                    numerator = tmp_lhs + tmp_rhs;
                    break;

                case sign :: subtraction:
                    denominator = lhs.rational.second * rhs.rational.second;

                    tmp_lhs;
                    tmp_rhs;

                    tmp_lhs = rational.first * denominator / lhs.rational.second;
                    tmp_rhs = rhs.rational.first * denominator / rhs.rational.second;

                    numerator = tmp_lhs - tmp_rhs;
                    break;

                case sign :: multiplication:
                    numerator = lhs.rational.first * rhs.rational.first;
                    denominator = lhs.rational.second * rhs.rational.second;
                    break;

                default:
                    throw;
            }

            int _gsd = gcd(numerator, denominator);

            return Rational(numerator / _gsd, denominator / _gsd);
        }

        Rational Rational :: operator + (const Rational & rhs)
        {
            return calculations(* this, rhs, sign :: addition);
        }

        Rational Rational :: operator - (const Rational & rhs)
        {
            return calculations(* this, rhs, sign :: subtraction);
        }

        Rational Rational :: operator * (const Rational & rhs)
        {
            return calculations(* this, rhs, sign :: multiplication);

        }

        Rational Rational :: operator / (const Rational & rhs)
        {
            Rational tmp(rhs.rational.second, rhs.rational.first);

            return calculations(* this, tmp, sign :: multiplication);
        }

        Rational :: operator double()
        {
            return double(rational.first) / rational.second;
        }

        Rational :: operator bool()
        {
            return rational.first != 0;
        }

        bool Rational :: isNaN()
        {
            return rational.first == 0 && rational.second == 0;
        }