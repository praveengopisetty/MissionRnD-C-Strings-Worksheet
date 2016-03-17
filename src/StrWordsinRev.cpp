/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
char * reverse(char * s, int min, int max)
{
	char temp;
	for (; min < max; max--, min++)
	{
		temp = s[min];
		s[min] = s[max];
		s[max] = temp;
	}
	return s;

}
void str_words_in_rev(char *input, int len)
{

	int i = 0, count = 0, last = 0;
	input = reverse(input, 0, len - 1);
	while (input[i] != '\0')
	{
		if (input[i] == ' '&&input[i - 1] != ' ')
		{
			if (count == 0)
			{
				count++;
				reverse(input, 0, i - 1);
			}
			else
			{
				reverse(input, last, i - 1);
			}
		}
		else if (input[i] != ' '&& input[i - 1] == ' ' && i>0)
		{
			last = i;
		}
		i++;
	}
	reverse(input, last, len - 1);

}