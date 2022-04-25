// https://leetcode.com/problems/relative-ranks/

#include <functional>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<string> findRelativeRanks(vector<int>& score)
	{
		return normalization(score);
	}

private:
	// time: O(n * log(n))
	// space: O(n)
	std::vector<std::string> normalization(std::vector<int>& score)
	{
		std::vector<size_t> indices(score.size());
		std::iota(begin(indices), end(indices), 0);
		std::sort(begin(indices), end(indices), [&score](size_t i, size_t j) { return score[i] > score[j]; });

		std::vector<std::string> ranks(score.size());
		for (size_t i = 0; i < score.size(); ++i)
			ranks[indices[i]] = (i == 0 ? "Gold Medal" : i == 1 ?
					"Silver Medal" : i == 2 ? "Bronze Medal" : std::to_string(i + 1));


		return ranks;
	}

	// time: O(n * log(n))
	// space: O(n)
	std::vector<std::string> sort_and_map(const std::vector<int>& score)
	{
		std::vector<int> sorted(score);
		std::sort(begin(sorted), end(sorted), std::greater<int>());
		std::unordered_map<int, size_t> ranks;
		for (size_t i = 0; i < sorted.size(); ++i)
			ranks[sorted[i]] = i + 1;

		std::vector<std::string> res(score.size());
		for (size_t i = 0; i < score.size(); ++i) {
			auto rank = ranks[score[i]];
			std::string description;
			if (rank == 1)
				description = "Gold Medal";
			if (rank == 2)
				description = "Silver Medal";
			if (rank == 3)
				description = "Bronze Medal";
			if (rank > 3)
				description = std::to_string(rank);
			res[i] = std::move(description);
		}

		return res;
	}
};

int main(int argc, char** argv)
{
}
