// https://leetcode.com/problems/two-sum-iii-data-structure-design/

#include <limits>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

class TwoSum
{
	public:
		TwoSum()
		{
		}

		void add(int num)
		{
			if (!freq.count(num))
				nums.push_back(num);
			++freq[num];
		}

		bool find(int target)
		{
			for (int n : nums) {
				long complement = static_cast<long>(target) - n;
				if (!freq.count(complement))
					continue;
				if (freq[complement] > 1 || complement != n)
					return true;
			}

			return false;
		}

	private:
		vector<int> nums;
		unordered_map<int, int> freq;
};

int main(int argc, char** argv)
{
	TwoSum s;
	s.add(1);
	cout << s.find(std::numeric_limits<int>::min()) << '\n';
}
