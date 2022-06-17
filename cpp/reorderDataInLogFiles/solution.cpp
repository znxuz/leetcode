// https://leetcode.com/problems/reorder-data-in-log-files/

#include <algorithm>
#include <sstream>
#include <cctype>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    vector<string> reorderLogFiles(vector<string>& logs) 
    {
	return part_and_sort(logs);
    }

private:
    std::vector<std::string> part_and_sort(std::vector<std::string>& logs)
    {
	auto it = std::stable_partition(begin(logs), end(logs),
		[](const std::string& s) { return std::isalpha(s.back()); });

	std::sort(begin(logs), it,
		[](const std::string& s1, const std::string& s2) {
		    auto sv1 = std::string_view(s1);
		    auto sv2 = std::string_view(s2);
		    auto log1 = sv1.substr(s1.find(' ') + 1);
		    auto log2 = sv2.substr(s2.find(' ') + 1);
		    return (log1 == log2 ? s1 < s2 : log1 < log2);
		});

	return logs;
    }

    std::vector<std::string> stable_sort_all(std::vector<std::string>& logs)
    {
	std::stable_sort(begin(logs), end(logs), custom_cmp);
	return logs;
    }

    static bool custom_cmp(const std::string& s1, const std::string& s2)
    {
	if (is_digit_log(s1) && is_digit_log(s2))
	    return false;
	if (is_digit_log(s1) || is_digit_log(s2))
	    return (is_digit_log(s1) ? false : true);

	auto id1 = std::string();
	auto id2 = std::string();
	auto i = 0ul;
	auto j = 0ul;
	while (s1[i] != ' ')
	    id1.push_back(s1[i++]);
	while (s2[j] != ' ')
	    id2.push_back(s2[j++]);
	auto rest1 = s1.substr(i);
	auto rest2 = s2.substr(j);
	return (rest1 != rest2 ? rest1 < rest2 : id1 < id2);
    }

    static bool is_digit_log(const std::string& log)
    {
	return std::isdigit(log.back());
    }
};

int main(int argc, char** argv)
{
}
