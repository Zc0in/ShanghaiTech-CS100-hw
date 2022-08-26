#ifndef POLY_HPP_
#define POLY_HPP_

#include <stdlib.h>
#include <vector>
#include <math.h>

template <typename T>
class Poly
{
public:
  /* Default constructor */
  Poly();

  /* Constructor for a poly that's a constant number */
  Poly(T constant);

  /* Given a vector of coefficients */
  Poly(const std::vector<T> &coeffs);

  /* Given an rvalue reference of a vector of coefficients */
  Poly(std::vector<T> &&coeffs);

  /* Given an array of coefficients with size of the array*/
  Poly(T *coeffs, size_t numberCoeffs);

  /* Given an initializer_list */
  Poly(std::initializer_list<T> coeffs);

  virtual ~Poly() = default;

  /* Copying constructor */
  Poly(const Poly<T> &poly);

  /* Copying constructor with rvalue reference */
  Poly(Poly<T> &&poly);

  /* Assignment operator */
  Poly<T> &operator=(const Poly<T> &poly);

  /* Assignment operator with rvalue reference */
  Poly<T> &operator=(Poly<T> &&poly);

  /*
   * Below are operations of polynomials.
   * They are quite self-explanatory.
   */

  Poly<T> operator+(const Poly<T> &rhs) const;
  Poly<T> operator-(const Poly<T> &rhs) const;
  Poly<T> operator*(const Poly<T> &rhs) const;

  Poly<T> &operator+=(const Poly<T> &rhs);
  Poly<T> &operator-=(const Poly<T> &rhs);
  Poly<T> &operator*=(const Poly<T> &rhs);

  /* 
   * This function evaluates the polynomial at "param",
   * and returns the value of evaluation.
   * For example, evaluating x+3 at param=7 gives 10. 
   */
  T eval(T param) const;

  /* 
   * This function takes the derivative of the polynomial,
   * and returns a new polynomial of its derivative.
   * For example, calling this function for x^2
   * will return a polynomial 2x.
   */
  Poly<T> der() const;

  /*
  * This function returns a pair of:
  * 1. the value (evaluation) of the polynomial at "param".
  * 2. the value of the first-order derivative of the polynomial at "param".
  * For example, calling this operator for x^2-2x at "param"=4
  * will return (8, 6).
  */
  std::pair<T, T> operator()(T param) const;

private:
  std::vector<T> _coeffs;
};

template <typename T>
Poly<T>::Poly()
{
  _coeffs.push_back(0);
}

template <typename T>
Poly<T>::Poly(T constant)
{
  _coeffs.push_back(constant);
}

template <typename T>
Poly<T>::Poly(const std::vector<T> &coeffs)
{
  _coeffs = coeffs;
}

template <typename T>
Poly<T>::Poly(std::vector<T> &&coeffs)
{
  _coeffs = coeffs;
}

template <typename T>
Poly<T>::Poly(T *coeffs, size_t numberCoeffs)
{
  for (int i = 0; i < numberCoeffs; i++)
  {
    _coeffs.push_back(coeffs[i]);
  }
}

template <typename T>
Poly<T>::Poly(std::initializer_list<T> coeffs)
{
  for (auto it = coeffs.begin(); it != coeffs.end(); it++)
  {
    _coeffs.push_back(*it);
  }
}

template <typename T>
Poly<T>::Poly(const Poly<T> &poly)
{
  for (auto it = poly._coeffs.begin(); it != poly._coeffs.end(); it++)
  {
    _coeffs.push_back(*it);
  }
}

template <typename T>
Poly<T>::Poly(Poly<T> &&poly)
{
  for (auto it = poly._coeffs.begin(); it != poly._coeffs.end(); it++)
  {
    _coeffs.push_back(*it);
  }
}

template <typename T>
Poly<T> &Poly<T>::operator=(const Poly<T> &poly)
{
  _coeffs.assign(poly._coeffs.begin(), poly._coeffs.end());
}

template <typename T>
Poly<T> &Poly<T>::operator=(Poly<T> &&poly)
{
  _coeffs.assign(poly._coeffs.begin(), poly._coeffs.end());
}

template <typename T>
Poly<T> Poly<T>::operator+(const Poly<T> &rhs) const
{
  std::vector<T> poly;
  std::vector<T> left_poly = _coeffs;
  std::vector<T> right_poly = rhs._coeffs;
  if (rhs._coeffs.size() <= _coeffs.size())
  {
    for (int i = 0; i < _coeffs.size() - _coeffs.size(); i++)
    {
      right_poly.push_back(0);
    }
  }
  else
  {
    for (int i = 0; i < rhs._coeffs.size() - rhs._coeffs.size(); i++)
    {
      left_poly.push_back(0);
    }
  }
  for (int i = 0; i < _coeffs.size(); i++)
  {
    poly.push_back(left_poly[i] + right_poly[i]);
  }
  return Poly<T>(poly);
}

template <typename T>
Poly<T> Poly<T>::operator-(const Poly<T> &rhs) const
{
  std::vector<T> poly;
  std::vector<T> left_poly = _coeffs;
  std::vector<T> right_poly = rhs._coeffs;
  if (rhs._coeffs.size() <= _coeffs.size())
  {
    for (int i = 0; i < _coeffs.size() - _coeffs.size(); i++)
    {
      right_poly.push_back(0);
    }
  }
  else
  {
    for (int i = 0; i < rhs._coeffs.size() - rhs._coeffs.size(); i++)
    {
      left_poly.push_back(0);
    }
  }
  for (int i = 0; i < _coeffs.size(); i++)
  {
    poly.push_back(left_poly[i] - right_poly[i]);
  }
  return Poly<T>(poly);
}

template <typename T>
Poly<T> Poly<T>::operator*(const Poly<T> &rhs) const
{
  std::vector<T> temp;
  temp.resize(_coeffs.size() * rhs._coeffs.size());
  for (int i = 0; i < _coeffs.size(); i++)
  {
    for (int j = 0; j < rhs._coeffs.size(); j++)
    {
      temp[i + j] += _coeffs[i] * rhs._coeffs[j];
    }
  }
  Poly<T> poly(temp);
  return poly;
}

template <typename T>
Poly<T> &Poly<T>::operator+=(const Poly<T> &rhs)
{
  std::vector<T> right_poly = rhs._coeffs;
  if (rhs._coeffs.size() >= _coeffs.size())
  {
    for (int i = 0; i < rhs._coeffs.size() - _coeffs.size(); i++)
    {
      _coeffs.push_back(0);
    }
  }
  else
  {
    for (int i = 0; i < _coeffs.size() - rhs._coeffs.size(); i++)
    {
      right_poly.push_back(0);
    }
  }
  for (int i = 0; i < _coeffs.size(); i++)
  {
    _coeffs[i] += right_poly[i];
  }
  return *this;
}

template <typename T>
Poly<T> &Poly<T>::operator-=(const Poly<T> &rhs)
{
  std::vector<T> right_poly = rhs._coeffs;
  if (rhs._coeffs.size() >= _coeffs.size())
  {
    for (int i = 0; i < rhs._coeffs.size() - _coeffs.size(); i++)
    {
      _coeffs.push_back(0);
    }
  }
  else
  {
    for (int i = 0; i < _coeffs.size() - rhs._coeffs.size(); i++)
    {
      right_poly.push_back(0);
    }
  }
  for (int i = 0; i < _coeffs.size(); i++)
  {
    _coeffs[i] -= right_poly[i];
  }
  return *this;
}

template <typename T>
Poly<T> &Poly<T>::operator*=(const Poly<T> &rhs)
{
  std::vector<T> poly;
  poly.resize(_coeffs.size() + rhs._coeffs.size());
  for (int i = 0; i < _coeffs.size(); i++)
  {
    for (int j = 0; j < rhs._coeffs.size(); j++)
    {
      poly[i + j] += _coeffs[i] * rhs._coeffs[j];
    }
  }
  _coeffs.clear();
  for (int i = 0; i < poly.size(); i++)
  {
    _coeffs.push_back(poly[i]);
  }
  return *this;
}

template <typename T>
T Poly<T>::eval(T param) const
{
  T ans = 0;
  for (int i = 0; i < _coeffs.size(); i++)
  {
    ans += _coeffs[i] * pow(param, i);
  }
  return ans;
}

template <typename T>
Poly<T> Poly<T>::der() const
{
  std::vector<T> poly;
  if (_coeffs.size() == 1)
  {
    return Poly<T>(0);
  }
  else
  {
    for (int i = 0; i < _coeffs.size() - 1; i++)
    {
      poly.push_back(_coeffs[i + 1] * (i + 1));
    }
    return Poly<T>(poly);
  }
}

template <typename T>
std::pair<T, T> Poly<T>::operator()(T param) const
{
  return std::pair<T, T>(eval((param)), (this->der()).eval(param));
}
#endif