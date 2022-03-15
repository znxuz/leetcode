// https://leetcode.com/problems/read-n-characters-given-read4/

#include <memory>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

int read4(char *buf4);

/**
 * @param buf Destination buffer
 * @param n   Number of characters to read
 * @return    The number of actual characters read
 */

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		int read(char *buf, int n)
		{
			int idx = 0;
			int read_cnt = 0;
			while (n > 0 && (read_cnt = read4(buf + idx))) {
				n -= read_cnt;
				idx += read_cnt;
				while (n < 0) {
					buf[--idx] = 0;
					n++;
				}
			}

			return idx;
		}

		// time: O(n)
		// space: O(1)
		int read_own_buf(char *buf, int n)
		{
			int res = 0;
			int read_cnt = 0;
			size_t buf_len = 4;
			char* own_buf = new char[buf_len];
			int buf_idx = 0;
			while (n > 0 && (read_cnt = read4(own_buf))) {
				for (int i = 0; i < read_cnt && n > 0; ++i) {
					buf[buf_idx++] = own_buf[i];
					n--;
					res++;
				}
			}

			delete[] own_buf;

			return res;
		}
};

int main(int argc, char** argv)
{
}
