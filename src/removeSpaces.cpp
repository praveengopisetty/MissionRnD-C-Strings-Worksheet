/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include<stdio.h>

char removeSpaces(char *str)
{
	int i = 0, j = 0, k;

	if (str == '\0' || str == NULL)
		return '\0';

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			j = i + 1;
			k = i;
			for (j = i + 1; str[j] == ' '; j++);
			for (; ; j++, k++)
			{
				str[k] = str[j];
				if (str[j] == '\0')
				{
					str[k] = str[j];
					break;
				}
			}
		}
	}
	return *str;
}