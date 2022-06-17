// https://leetcode.com/problems/unique-email-addresses/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int numUniqueEmails(vector<string>& emails) 
    {
	std::unordered_set<std::string> st;
	for (const auto& e : emails) {
	    std::string normalized_e;
	    size_t i = 0;
	    for (; e[i] != '@' && e[i] != '+'; ++i) {
		if (e[i] != '.')
		    normalized_e.push_back(e[i]);
	    }
	    while (e[i] != '@')
		++i;
	    normalized_e += e.substr(i);
	    st.insert(std::move(normalized_e));
	}

	return st.size();
    }
};

int main(int argc, char** argv)
{
}
