// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

class Solution
{
	public:
		int finalValueAfterOperations(vector<string>& operations)
		{
			return accumulate(operations.begin(), operations.end(), 0, [](int x, const auto& o) {
					return x + (o[1] == '-' ? -1 : 1); });
		}

		int finalValueAfterOperationsLoop(vector<string>& operations)
		{
			int cnt = 0;
			for (auto& o : operations)
				cnt += o[1] == '-' ? -1 : 1;
			return cnt;
		}
};

int main(int argc, char** argv)
{
}
