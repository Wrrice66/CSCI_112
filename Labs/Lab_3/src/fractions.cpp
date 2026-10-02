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
    sum.simplify();
    return sum;
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    Fraction diff;
    if (this->_denominator != frac._denominator)
    {
        diff._denominator = (this->_denominator * frac._denominator);
        diff._numerator = ((this->_numerator * frac._denominator) - (frac._numerator * this->_denominator));
    }
    else
    {
        diff._denominator = this->_denominator;
        diff._numerator = (this->_numerator - frac._numerator);
    }
    diff.simplify();
    return diff;
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    Fraction prod;
    prod._numerator = (this->_numerator) * (frac._numerator);
    prod._denominator = (this->_denominator) * (frac._denominator);
    prod.simplify();
    return prod;
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    Fraction quot;
    quot._numerator = (this->_numerator) * (frac._denominator);
    quot._denominator = (this->_denominator) * (frac._numerator);
    quot.simplify();
    return quot;
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    return Fraction(0, 1);
}

void fractions::Fraction::simplify()
{
    int gratComDen = gcd(this->_numerator, this->_denominator);
    this->_numerator = (this->_numerator / gratComDen);
    this->_denominator = (this->_denominator / gratComDen);
}

int fractions::Fraction::gcd(int a, int b)
{
    int i = 1;
    int concern = min(a, b);
    while(i <= concern)
    {
        if (a%i == 0 && b%i == 0)
            return i;
        else
            i++;
    }
    if ((max(a, b))%concern != 0)
        return 1;
    else
        return concern;
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    return false;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    return os;
}