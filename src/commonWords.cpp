/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

int stringLength(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++);

	return i;
}

int stringCompare(char *s1, char *s2)
{
	int len1 = 0, len2 = 0, i = 0;

	len1 = stringLength(s1);
	len2 = stringLength(s2);

	if (len1 != len2)
		return 1;

	for (i = 0; i < len1; i++)
		if (s1[i] != s2[i])
			return 1;

	return 0;
}

char ** commonWords(char *str1, char *str2)
{
	char **ptr1 = NULL, **ptr2 = NULL, **ptr = NULL, *auxptr = NULL;
	int i = 0, j = 0, k = 0, w1 = 0, w2 = 1, w = 0;

	if (str1 == NULL || str2 == NULL)
		return NULL;

	ptr1 = (char**)malloc(sizeof(char));
	ptr2 = (char**)malloc(sizeof(char));
	ptr = NULL;
	*auxptr = '\0';

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != ' ')
			auxptr[k++] = str1[i];

		if (str1[i] == ' ' && stringLength(auxptr) != 0)
		{
			auxptr[k] = '\0';
			ptr1[w1] = (char*)malloc(sizeof(char));
			k = 0;
			ptr1[w1++] = auxptr;
			auxptr = (char*)malloc(sizeof(char));
			*auxptr = '\0';
		}
	}

	if (stringLength(auxptr) != 0)
		ptr1[w1] = auxptr;

	auxptr = (char*)malloc(sizeof(char));
	*auxptr = '\0';

	for (i = 0; str2[i] != '\0'; i++)
	{
		if (str2[i] != ' ')
			auxptr[k++] = str1[i];

		if (str2[i] == ' ' && stringLength(auxptr) != 0)
		{
			auxptr[k] = '\0';
			ptr2[w2] = (char*)malloc(sizeof(char));
			k = 0;
			ptr2[w2++] = auxptr;
			auxptr = (char*)malloc(sizeof(char));
			*auxptr = '\0';
		}
	}

	if (stringLength(auxptr) != 0)
		ptr1[w2] = auxptr;

	k = (w1 < w2) ? w1 : w2;

	for (i = 0; i < k; i++)
		ptr[i] = (char*)malloc(sizeof(char));

	for (i = 0; i < w1; i++)
	{
		for (j = 0; j < w2; j++)
		{
			k = stringCompare(ptr1[i], ptr2[j]);

			if (k == 0)
			{
				ptr[w] = (char*)malloc(sizeof(char));

				ptr[w++] = ptr1[i];
			}
		}
	}

	return ptr;
}