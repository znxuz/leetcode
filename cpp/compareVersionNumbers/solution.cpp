// https://leetcode.com/problems/compare-version-numbers/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int compareVersion(string ver1, string ver2)
    {
	return straight_forward(ver1, ver2);
    }

private:
    // time: O(max(n, m))
    // space: O(max(n, m))
    int straight_forward(const std::string& ver1, const std::string& ver2)
    {
	size_t n = ver1.size();
	size_t m = ver2.size();
	size_t i = 0;
	size_t j = 0;
	while (i < n || j < m) {
	    int res = compare_rev(get_rev(ver1, i), get_rev(ver2, j));
	    if (res)
		return res;

	    ++i, ++j;
	}

	return 0;
    }

    int compare_rev(const std::string& rev1, const std::string& rev2)
    {
	size_t n = rev1.size();
	size_t m = rev2.size();
	if (n != m)
	    return n > m ? 1 : -1;
	while (n-- > 0) {
	    if (rev1[n] != rev2[n])
		return rev1[n] > rev2[n] ? 1 : -1;
	}

	return 0;
    }

    std::string get_rev(const std::string& version, size_t& i)
    {
	std::string rev;
	for (; i < version.size() && version[i] != '.'; ++i) {
	    if (version[i] != '0' || !rev.empty())
		rev.push_back(version[i]);
	}

	return rev;
    }
};

int main(int argc, char** argv)
{
    std::string s = "1.2";
    std::string t = "1.10";
    std::cout << Solution().compareVersion(s, t) << '\n';
}
