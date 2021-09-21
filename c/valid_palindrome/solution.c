// https://leetcode.com/problems/valid-palindrome/

#include "function.h"
#include <stdio.h>

bool isPalindrome(char *s)
{
	if (!s)
		return true;

	char *left = s;
	char *right = s + strlen(s) - 1;
	while (left < right) {
		if (!isalnum(*left)) {
			left++;
		} else if (!isalnum(*right)) {
			right--;
		} else if (tolower(*left) != tolower(*right)) {
			return false;
		} else {
			left++;
			right--;
		}
	}

	return true;
}
