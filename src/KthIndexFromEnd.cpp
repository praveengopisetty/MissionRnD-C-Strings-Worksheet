/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>
char KthIndexFromEnd(char *str, int K) {
	if (str == NULL || K < 0)
	{
		return '\0';
	}
	int i,len;
	for (i = 0; str[i] != '\0'; i++);
	len = i;
	if (K > len)
	{
		return '\0';
	}
	return str[len -1- K];
}