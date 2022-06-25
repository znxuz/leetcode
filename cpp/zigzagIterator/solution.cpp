// https://leetcode.com/problems/zigzag-iterator/

#include <list>

#include "helper.h"

using namespace std;
using namespace util;

class ZigzagIterator
{
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : iter(0)
    {
	vecs.push_back(v1);
	vecs.push_back(v2);
	indices.assign(2, 0);
	size = vecs.size();
	validate_iter();
    }

    int next() 
    {
	auto ret = vecs[iter][indices[iter]++];
	iter = (size > 1 ? ++iter % size : iter);
	validate_iter();

	return ret;
    }

    bool hasNext() 
    {
	return size;
    }

private:
    std::vector<std::vector<int>> vecs;
    std::vector<size_t> indices;
    size_t iter;
    size_t size;

    void validate_iter()
    {
	while (hasNext() && indices[iter] == vecs[iter].size())
	    iter = ++iter % size--;
    }
};

class ZigzagIteratorList 
{
public:
    ZigzagIteratorList(vector<int>& v1, vector<int>& v2)

    {
	iter_list.emplace_back(v1, 0);
	iter_list.emplace_back(v2, 0);
	cur = iter_list.begin();
	validate_iter();
    }

    int next() 

    {
	auto ret = cur->first[cur->second++];
	if (cur->second < cur->first.size())
	    cur = (++cur == iter_list.end() ? iter_list.begin() : cur);
	validate_iter();

	return ret;
    }

    bool hasNext() 

    {
	return !iter_list.empty();
    }

private:
    std::list<std::pair<std::vector<int>, size_t>> iter_list;
    std::list<std::pair<std::vector<int>, size_t>>::iterator cur;

    void validate_iter()

    {
	while (hasNext() && cur->second == cur->first.size()) 
	{
	    cur = iter_list.erase(cur);
	    if (cur == iter_list.end())
		cur = iter_list.begin();
	}
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char** argv)
{
    auto v1 = std::vector<int>
    {1, 2};
    auto v2 = std::vector<int>
    {3, 4, 5, 6, 7};
    auto s = ZigzagIterator(v1, v2);
    while (s.hasNext())
	std::cout << s.next();
}
