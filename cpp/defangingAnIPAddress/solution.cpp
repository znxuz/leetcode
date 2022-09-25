// https://leetcode.com/problems/defanging-an-ip-address/

#include <regex>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    string defangIPaddr(string address) 
    {
	return linear_scan(address);
    }

private:
    std::string linear_scan(const std::string &address)
    {
	auto ret = std::string();
	for (auto i = 0ul; i < address.size(); ++i)
	    address[i] == '.' ? ret.append("[.]") : ret.append(1, address[i]);
	return ret;
    }

    std::string one_liner_regex(const std::string &address)
    {
	return std::regex_replace(address, std::regex("\\."), "[.]");
    }
};

int main(int argc, char **argv)
{
}
