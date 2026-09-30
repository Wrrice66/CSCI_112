#include "../include/fractions.hpp"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    _numerator = numerator;
    if (denominator != 0)
    {
        _denominator = denominator;
    }
    else
    {
        _denominator = 1;
    }
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    Fraction sum;
    if (this->_denominator != frac._denominator)
    {
        sum._denominator = (this->_denominator * frac._denominator);
        sum._numerator = ((this->_numerator * frac._denominator) + (frac._numerator * this->_denominator));
    }
    else
    {
        sum._denominator = this->_denominator;
        sum._numerator = (this->_numerator + frac._numerator);
    }
    return sum;
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    return Fraction(0, 1);
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    return Fraction(0, 1);
}

void fractions::Fraction::simplify()
{

}

int fractions::Fraction::gcd(int a, int b)
{
    return 0;
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    return false;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    return os;
}