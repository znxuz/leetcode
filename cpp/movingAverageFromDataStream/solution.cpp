// https://leetcode.com/problems/moving-average-from-data-stream/

#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class MovingAverage
{
public:
	MovingAverage(int size) : top(), size(size), sum()
	{ }

	double next(int val)
	{
		sum += val;
		if (data.size() == size) {
			sum -= data[top];
			data[top] = val;
		} else  {
			data.push_back(val);
		}
		top = ++top % size;

		return sum / data.size();
	}
	// [1 2 3]

private:
	std::vector<int> data;
	size_t top;
	size_t size;
	double sum;
};

int main(int argc, char** argv)
{
}
