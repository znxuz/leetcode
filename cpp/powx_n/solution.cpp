// https://leetcode.com/problems/powx-n/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    double myPow(double x, int n)
    {
	return pow_by_squaring(x, n);
    }

private:
    double power_by_squaring_iter(double x, int n)
    {
	long N = n;
	if (N < 0)
	    x = 1 / x, N = -N;

	double ans = 1;
	double cur = x;
	for (long i = N; i; i >>= 1) {
	    if (i % 2)
		ans *= cur;
	    cur *= cur;
	}

	return ans;
    }

    double pow_by_squaring(double x, long n)
    {
	if (n < 0)
	    return pow_by_squaring(1 / x, -n);
	if (n == 0)
	    return 1.0;

	auto half = pow_by_squaring(x, n / 2);
	if (n % 2)
	    return half * half * x;
	return half * half;
    }

    // TLE
    double brute_force(double x, int n)
    {
	long N = n;
	if (N < 0)
	    x = 1 / x, N = -N;

	double ans = 1;
	for (int i = 0; i < N; ++i)
	    ans *= x;

	return ans;
    }
};

int main(int argc, char** argv)
{
}
