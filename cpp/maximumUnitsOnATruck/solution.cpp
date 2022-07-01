// https://leetcode.com/problems/maximum-units-on-a-truck/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int maximumUnits(vector<vector<int>>& box_types, int truck_size) 
    {
	return use_pq(box_types, truck_size);
    }

private:
    int use_pq(const std::vector<std::vector<int>>& box_types, int truck_size)
    {
	auto cmp_box_types = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
	    return lhs.second < rhs.second;
	};
	// pq reverse the sort order, because pq.top() == std::vector<T>::back()
	auto pq = std::priority_queue< std::pair<int, int>,
	     std::vector<std::pair<int, int>>,
	     decltype(cmp_box_types)>();

	for_each(begin(box_types), end(box_types),
		[&pq](const std::vector<int>& type) {
		    pq.push({type.front(), type.back()});
		});

	auto res = 0;
	while (!pq.empty() && truck_size) {
	    auto [cnt, units] = pq.top();
	    pq.pop();
	    res += std::min(truck_size, cnt) * units;
	    truck_size = std::max(0, truck_size - cnt);
	}

	return res;
    }

    int sort_it(std::vector<std::vector<int>>& box_types, int truck_size)
    {
	std::sort(begin(box_types), end(box_types),
		[](const std::vector<int>& type1, const std::vector<int>& type2) {
		return type1.back() > type2.back();
		});

	auto cnt = 0;
	for (const auto& type : box_types) {
	    cnt += std::min(type.front(), truck_size) * type.back();
	    truck_size = std::max(0, truck_size - type.front());
	}
	return cnt;
    }
};

int main(int argc, char** argv)
{
    auto box_types = std::vector<std::vector<int>>{{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    std::cout << Solution().maximumUnits(box_types, 10) << '\n';
}
