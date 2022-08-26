#ifndef FUNCTIONAL_FORMS_HPP_
#define FUNCTIONAL_FORMS_HPP_

#include <stdlib.h>
#include <math.h>

/* For all lambda functions below, if you are not clear how they work, please refer to the given example for details. */

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1+f2)(m) as first, and (d(f1+f2)/dx)(m) as second.
 */
auto derSum = [](auto f1, auto f2)
{
  //add your code here ...
  return [=](double m)
  { return std::pair<double, double>(f1(m).first + f2(m).first, f1(m).second + f2(m).second); };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1-f2)(m) as first, and (d(f1-f2)/dx)(m) as second.
 */
auto derSub = [](auto f1, auto f2)
{
  //add your code here ...
  return [=](double m)
  { return std::pair<double, double>(f1(m).first - f2(m).first, f1(m).second - f2(m).second); };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1*f2)(m) as first, and (d(f1*f2)/dx)(m) as second.
 */
auto derMul = [](auto f1, auto f2)
{
  //add your code here ...
  return [=](double m)
  { return std::pair<double, double>(f1(m).first * f2(m).first, f1(m).second * f2(m).first + f2(m).second * f1(m).first); };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1/f2)(m) as first, and (d(f1/f2)/dx)(m) as second.
 */
auto derDiv = [](auto f1, auto f2)
{
  //add your code here ...
  return [=](double m)
  { return std::pair<double, double>(f1(m).first / f2(m).first, (f1(m).second * f2(m).first - f2(m).second * f1(m).first) / pow(f2(m).first, 2)); };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1(f2))(m) as first, and (d(f1(f2))/dx)(m) as second.
 */
auto derComp = [](auto f1, auto f2)
{
  //add your code here ...
  return [=](double m)
  { return std::pair<double, double>(f2(f1(m).first).first, f2(f1(m).first).second * f1(m).second); };
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has [(f1)(m)]^exp as first, and (d(f1^exp)/dx)(m) as second.
 */
auto derPow = [](auto f, int exp)
{
  //add your code here ...
  return [=](double m)
  { return std::pair<double, double>(pow(f(m).first, exp), exp * pow(f(m).first, exp - 1) * f(m).second); };
};

#endif