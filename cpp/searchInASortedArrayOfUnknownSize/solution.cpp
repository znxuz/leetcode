// https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/

#include <climits>
#include <iostream>
#include <vector>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class ArrayReader
{
	public:
		int get(int index) const;
};

class Solution
{
	public:
		int search(const ArrayReader& reader, int target)
		{
			int boundary = get_boundary(reader, target);
			return iter(reader, boundary >> 1, boundary, target);
		}

	private:
		int get_boundary(const ArrayReader& reader, const int target)
		{
			int boundary = 1;
			while (reader.get(boundary) < target)
				boundary <<= 1;

			return boundary;
		}

		int iter(const ArrayReader& reader, int lo, int hi, const int target)
		{
			while (lo <= hi) {
				int md = lo + (hi - lo) / 2;
				int res = reader.get(md);
				if (res == target)
					return md;
				else if (res > target)
					hi = md - 1;
				else
					lo = md + 1;
			}

			return -1;
		}

		int rec(const ArrayReader& reader, int lo, int hi, const int target)
		{
			if (lo > hi)
				return -1;

			int md = lo + (hi - lo) / 2;
			int res = reader.get(md);
			if (res == target)
				return md;
			else if (res > target)
				return rec(reader, lo, md - 1, target);
			return rec(reader, md + 1, hi, target);
		}
};

int main(int argc, char** argv)
{
}
