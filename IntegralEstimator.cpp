#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>

#include <boost/random.hpp>

#include "IntegralEstimator.h"

using namespace std;

const size_t N = 2000;

IntegralEstimator::IntegralEstimator(Function &f) : f(f)

{
  cout << "constructor ..." << endl;
}

IntegralEstimator::IntegralEstimator(const IntegralEstimator &ie) : f(ie.f)
{
  cout << "copy constructor ..." << endl;
}

IntegralEstimator::~IntegralEstimator()
{
  cout << "destructor ..." << endl;
}

IntegralEstimator &IntegralEstimator::operator=(const IntegralEstimator &ie)
{

  if (this != &ie)
  {

    f = ie.f;
  }

  cout << "assignment operator ..." << endl;

  return *this;
}

double IntegralEstimator::getIntegral(double a, double b)
{

  int counted = 0;
  int notcounted = 0;
  double density = 0;
  // std::default_random_engine   dre;
  mt19937_64 dre;

  uniform_real_distribution<double> urd(a, b);

  double y = 0;

  for (int i = 0; i <= N; ++i)
  {

    double x = urd(dre);
    y += f(x);
  }

  return y * (b - a) / N;
}

Function::~Function()
{
}

double Function::operator()(double x)
{

  return pow(x, 2);
}

int main()
{

  cout << "Estimating the integral of function: x^2" << endl;

  Function function;
  IntegralEstimator ie(function);

  cout << "estimation [0,2]: " << ie.getIntegral(0, 2) << endl;
}
