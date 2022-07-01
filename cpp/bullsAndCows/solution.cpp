// https://leetcode.com/problems/bulls-and-cows/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    string getHint(string secret, string guess) 
    {
	return one_ass(secret, guess);
    }

private:
    std::string one_ass(const std::string& secret, const std::string& guess)
    {
	auto freq = std::unordered_map<char, int>();
	auto bulls = 0u;
	auto cows = 0u;
	for (auto i = 0ul; i < secret.size(); ++i) {
	    if (secret[i] == guess[i]) {
		++bulls;
		continue;
	    }
	    if (freq[guess[i]]++ < 0)
		++cows;
	    if (freq[secret[i]]-- > 0)
		++cows;
	}

	return std::to_string(bulls) + "A" +
	    std::to_string(cows) + "B";
    }

    std::string two_passes(const std::string& secret, const std::string& guess)
    {
	auto bulls = 0u;
	auto cows = 0u;
	auto mp = std::unordered_map<char, size_t>();
	auto waitlist = std::vector<char>();
	for (auto i = 0ul; i < guess.size(); ++i) {
	    if (secret[i] == guess[i]) {
		++bulls;
	    } else {
		waitlist.push_back(guess[i]);
		++mp[secret[i]];
	    }
	}

	while (!waitlist.empty()) {
	    auto c = waitlist.back();
	    waitlist.pop_back();
	    if (mp.count(c) && ++cows && !--mp[c])
		mp.erase(c);
	}

	return std::to_string(bulls) + "A" +
	    std::to_string(cows) + "B";
    }
};

template<typename... types>
void test(types&&... args)
{
    auto res = Solution().getHint(std::forward<types>(args)...);
    std::cout << res << '\n';
}

int main(int argc, char** argv)
{
    test("1807", "7810");
    test("1123", "0111");
    test("1122", "1222");
}
