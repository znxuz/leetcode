// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <array>
#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>
#include <unordered_map>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		vector<string> letterCombinations(string digits)
		{
			return rec_dfs(digits);
		}

		vector<string> rec_dfs(string& digits) {
			vector<string> res;
			if (digits.empty())
				return res;

			vector<vector<char>> lists;
			for (char d : digits)
				lists.push_back(get_letters(d - '0'));
			back_track(digits, 0, lists, string(), res);
			return res;
		}

		void back_track(const string& digits, int idx,
				const vector<vector<char>>& lists,  string s, vector<string>& res)
		{
			if (idx == lists.size()) {
				res.push_back(s);
				return;
			}

			const vector<char>& list = lists[idx];
			for (int i = 0; i < list.size(); ++i) {
				s.push_back(list[i]);
				back_track(digits, idx + 1, lists, s, res);
				s.pop_back();
			}
		}

		vector<string> iter_bfs(string& digits)
		{
			vector<string> res;
			if (digits.empty())
				return res;

			vector<vector<char>> lists;
			for (char d : digits)
				lists.push_back(get_letters(d - '0'));

			res.push_back("");
			for (const vector<char>& l : lists) {
				vector<string> tmp;
				for (char c : l)
					for (const auto& s : res)
						tmp.push_back({s + c});
				res = move(tmp);
				// res.swap(tmp);
			}

			return res;
		}

		vector<char> get_letters(int num)
		{
			char start = 'a' + (num - 2) * 3;
			if (num > 7)
				start += 1;
			vector<char> letters;
			for (int i = 0; i < ((num == 7 || num == 9) ? 4 : 3); ++i)
				letters.push_back(start + i);

			return letters;
		}
};

int main(int argc, char** argv)
{
	string digits = "234";
	print_vector(Solution().letterCombinations(digits));
}
