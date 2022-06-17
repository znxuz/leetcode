// https://leetcode.com/problems/long-pressed-name/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    bool isLongPressedName(string name, string typed) 
    {
	return improved(name, typed);
    }

private:
    bool improved(const std::string& name, const std::string& typed)
    {
	size_t i = 0;
	for (size_t j = 0; j < typed.size(); ++j) {
	    if (i < name.size() && name[i] == typed[j])
		++i;
	    else if (!j || typed[j] != typed[j - 1])
		return false;
	}

	return i == name.size();
    }

    bool two_ptrs(const std::string& name, const std::string& typed)
    {
	size_t j = 0;
	for (size_t i = 0; i < name.size(); ++i) {
	    if (j == typed.size() || typed[j] != name[i])
		return false;
	    if (i + 1 < name.size() && name[i + 1] == name[i]) {
		++j;
		continue;
	    }
	    while (j < typed.size() && typed[j] == name[i])
		++j;
	}
	while (j < typed.size()) {
	    if (j > 0 && typed[j] != typed[j - 1])
		return false;
	    ++j;
	}

	return true;
    }
};

int main(int argc, char** argv)
{
}
