// https://leetcode.com/problems/isomorphic-strings/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		bool isIsomorphic(string s, string t) const
		{
			int left_map[128]{};
			int right_map[128]{};

			for (size_t i = 0; i < s.size(); ++i) {
				int left = s[i];
				int right = t[i];
				if (!left_map[right] && !right_map[left]) {
					left_map[right] = left;
					right_map[left] = right;
				} else if (left_map[right] != left || right_map[left] != right) {
					return false;
				}
			}

			return true;
		}
};

static void test(const Solution& sol, const std::string& s, const std::string& t)
{
	std::cout << "s: " << s << ", t: " << t << " - isIsomorphic: ";
	std::cout << std::boolalpha << sol.isIsomorphic(s, t) << '\n';
}

int main(int argc, char** argv)
{
	Solution sol;
	test(sol, "egg", "add");
	test(sol, "foo", "bar");
	test(sol, "paper", "title");
}
