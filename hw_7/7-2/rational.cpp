#include "rational.hpp"

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

Rational::Rational()
{
    m_numerator = 0;
    m_denominator = 1;
}
Rational::Rational(int value)
{
    m_numerator = value;
    m_denominator = 1;
}
Rational::Rational(int p, unsigned int q)
{
    if (q == 0)
    {
        std::cout << "ERROR: initializing with a denominator of 0!" << std::endl;
        m_numerator = 0;
        m_denominator = 1;
    }
    int a = gcd(abs(p), abs((int)(q)));

    m_numerator = p / a;
    m_denominator = q / a;
}
Rational &Rational::operator=(const Rational &that)
{
    m_numerator = that.m_numerator;
    m_denominator = that.m_denominator;
    return *this;
}
Rational Rational::operator+(Rational that) const
{
    int numerator, denominator;
    numerator = m_numerator * (int)(that.m_denominator) + (int)(m_denominator) * (int)(that.m_numerator);
    denominator = m_denominator * that.m_denominator;
    return Rational(numerator, denominator);
}
Rational &Rational::operator+=(Rational that)
{
    m_numerator = m_numerator * (int)(that.m_denominator) + (int)(m_denominator) * (int)(that.m_numerator);
    m_denominator = m_denominator * that.m_denominator;
    return *this;
}
Rational Rational::operator-(Rational that) const
{
    int numerator, denominator;
    numerator = m_numerator * (int)(that.m_denominator) - (int)(m_denominator) * (int)(that.m_numerator);
    denominator = m_denominator * that.m_denominator;
    return Rational(numerator, denominator);
}
Rational &Rational::operator-=(Rational that)
{
    m_numerator = m_numerator * (int)(that.m_denominator) - (int)(m_denominator) * (int)(that.m_numerator);
    m_denominator = m_denominator * that.m_denominator;
    return *this;
}
Rational Rational::operator*(Rational that) const
{
    int numerator, denominator;
    numerator = m_numerator * that.m_numerator;
    denominator = m_denominator * that.m_denominator;
    return Rational(numerator, denominator);
}
Rational &Rational::operator*=(Rational that)
{
    m_numerator = m_numerator * that.m_numerator;
    m_denominator = m_denominator * that.m_denominator;
    return *this;
}
Rational Rational::operator/(Rational that) const
{
    int numerator, denominator;
    numerator = abs(m_numerator) * (int)(that.m_denominator);
    denominator = m_denominator * abs(that.m_numerator);
    if (denominator == 0)
    {
        std::cout << "ERROR: dividing by 0!" << std::endl;
        return Rational();
    }
    if (that.m_numerator * m_numerator < 0)
    {
        return Rational(-1 * numerator, denominator);
    }
    return Rational(numerator, denominator);
}
Rational &Rational::operator/=(Rational that)
{
    int numerator, denominator;
    numerator = abs(m_numerator) * (int)(that.m_denominator);
    denominator = m_denominator * abs(that.m_numerator);
    if (denominator == 0)
    {
        std::cout << "ERROR: dividing by 0!" << std::endl;
        m_numerator = 0;
        m_denominator = 1;
    }
    if (that.m_numerator * m_numerator < 0)
    {
        m_numerator = -1 * numerator;
        m_denominator = denominator;
    }
    else
    {
        m_numerator = numerator;
        m_denominator = denominator;
    }
    return *this;
}
bool Rational::operator==(Rational that) const
{
    if ((float)(m_numerator) / (float)(m_denominator) == (float)(that.m_numerator) / (float)(that.m_denominator))
    {
        return true;
    }
    return false;
}
bool Rational::operator<(Rational that) const
{
    if ((float)(m_numerator) / (float)(m_denominator) < (float)(that.m_numerator) / (float)(that.m_denominator))
    {
        return true;
    }
    return false;
}
std::ostream &operator<<(std::ostream &os, const Rational &number)
{
    int pp = number.m_numerator;
    unsigned int qq = number.m_denominator;
    if (qq == 1 || pp == 0)
    {
        os << pp;
    }
    else
    {
        int a = gcd(abs(pp), abs((int)(qq)));
        pp /= a;
        qq /= a;
        if (qq == 1)
        {
            os << pp;
        }
        else
        {
            os << pp << "/" << qq;
        }
    }
    return os;
}