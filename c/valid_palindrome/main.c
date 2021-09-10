#include <stdio.h>
#include "function.h"

int main(void)
{
	char *s = "A man, a plan, a canal: Panama";
	printf("%s\n", isPalindrome(s) ? "true" : "false");
}
