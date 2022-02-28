// https://leetcode.com/problems/integer-to-roman/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
	public:
		string intToRoman(int num)
		{
			vector<string> map(1001);
			map[1000] = "M";
			map[900] = "CM";
			map[500] = "D";
			map[400] = "CD";
			map[100] = "C";
			map[90] = "XC";
			map[50] = "L";
			map[40] = "XL";
			map[10] = "X";
			map[9] = "IX";
			map[5] = "V";
			map[4] = "IV";
			map[1] = "I";

			string res;
			for (int i = map.size() - 1; i > 0; --i) {
				if (!empty(map[i])) {
					while (num / i) {
						res += map[i];
						num -= i;
					}
				}
			}

			return res;
		}
};

int main(int argc, char** argv)
{
	int i = 9;
	cout << Solution().intToRoman(i) << '\n';
}
