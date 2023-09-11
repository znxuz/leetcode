// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/?envType=daily-question&envId=2023-09-11

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        auto res = std::vector<std::vector<int>>();
        auto groups = std::vector<std::vector<int>>(groupSizes.size());

        for (size_t i = 0; i < groupSizes.size(); ++i) {
            auto& group = groups[groupSizes[i] - 1];
            group.push_back(i);
            if (group.size() == groupSizes[i]) {
                res.push_back(std::move(group));
                group.clear();
            }
        }

        return res;
    }
};

int main(int argc, char **argv)
{
    auto vec = std::vector<int>{3,3,3,3,3,1,3};
    auto res = Solution().groupThePeople(vec);
    for (const auto& v : res)
        print_container(v);
}
