#include <stdbool.h>

// reduce time complexity by adding another array for t
bool isIsomorphic(char *s, char *t)
{
	char map_s[256] = {0};
	char map_t[256] = {0};

	while (*s || *t) {
		if ((map_s[*s] || map_t[*t])
			&& (map_s[*s] != *t || map_t[*t] != *s))
				return false;
		map_s[*s] = *t;
		map_t[*t] = *s;
		s++;
		t++;
	}

	return *s || *t ? false : true;
}
