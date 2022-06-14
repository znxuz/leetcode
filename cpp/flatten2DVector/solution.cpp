// https://leetcode.com/problems/flatten-2d-vector/

#include <stdexcept>

#include "helper.h"

using namespace std;
using namespace util;

class Vector2D 
{
public:
    Vector2D(vector<vector<int>>& vec) : vec_ptr(vec)
    {
	advance_next();
    }

    int next() 
    {
	if (!hasNext())
	    throw std::out_of_range("");

	int ret = vec_ptr[i][j++];
	advance_next();
	return ret;
    }

    bool hasNext() 
    {
	return i < vec_ptr.size() && j < vec_ptr[i].size();
    }

private:
    std::vector<std::vector<int>>& vec_ptr;
    size_t i = 0;
    size_t j = 0;

    void advance_next()
    {
	if (i >= vec_ptr.size() || j < vec_ptr[i].size())
	    return;

	j = 0;
	while (++i < vec_ptr.size() && j >= vec_ptr[i].size());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(int argc, char** argv)
{
}
