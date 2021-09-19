// https://leetcode.com/problems/isomorphic-strings/

#include "function.h"

// iterate every character of *s and store the correcponding
// value inside a map array
// try to find duplicates in every iteration
bool isIsomorphic(char *s, char *t)
{
	char map[127];
	for (int i = 0; i < 127; i++)
		map[i] = '\0';

	while (*s && *t) {
		int index = *s;
		if (map[index] && map[index] != *t)
			return false;
		for (int i = 0; i < sizeof map; i++)
			if (map[i] == *t && i != index)
				return false;

		map[index] = *t;
		s++;
		t++;
	}

	return *s || *t ? false : true;
}
