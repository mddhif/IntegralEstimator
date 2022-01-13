#ifndef __INTEGRALESTIMATOR__
#define __INTEGRALESTIMATOR__

class Function
{

public:
	~Function();
	double operator()(double x);
};

class IntegralEstimator
{

public:
	IntegralEstimator(Function &f);
	IntegralEstimator(const IntegralEstimator &ie);
	~IntegralEstimator();
	IntegralEstimator &operator=(const IntegralEstimator &ie);

	double getIntegral(double a, double b);

private:
	Function &f;
};

#endif
