// https://leetcode.com/problems/count-and-say/

#include <iostream>
#include <vector>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		// constraints: 1 <= n <= 30
		// time: O(n)
		// space: O(n)
		string countAndSay(int n)
		{
			return rec(n);
		}

		string rec(int n)
		{
			if (n == 1)
				return "1";

			string res;
			string prev = rec(n - 1);
			for (int i = 0; i < prev.size();) {
				char cur = prev[i];
				char cnt = 1;
				while (i + cnt < prev.size() && prev[i + cnt] == cur)
					cnt++;
				res.append(1, cnt + '0').append(1, cur);
				i += cnt;
			}
			
			return res;
		}

		string iter(int n)
		{
			string res = "1";
			for (int i = 1; i < n; ++i) {
				string tmp;
				for (int j = 0; j < res.size();) {
					char cur = res[j];
					char cnt = 1;
					while (j + cnt < res.size() && res[j + cnt] == cur)
						cnt++;
					tmp.append(1, cnt + '0').append(1, cur);
					j += cnt;
				}
				res = move(tmp);
			}

			return res;
		}
};

int main(int argc, char** argv)
{
	Solution s;
	for (int i = 1; i < 11; ++i)
		cout << s.countAndSay(i) << '\n';
}
