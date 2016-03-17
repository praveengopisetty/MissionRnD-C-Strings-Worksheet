/*
OVERVIEW: Given a float number ,Convert it into a string

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *reverseString(char *str, int size)
{
	int i = 0, j = 0;
	char ch;

	for (i = 0, j = size - 1; i <= j; i++, j--)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}

	return str;
}

int power(int a, int b)
{
	int ans = 1;

	while (b > 0)
	{
		ans *= a;
		b--;
	}

	return ans;
}

void number_to_str(float number, char *str, int afterdecimal)
{
	int temp = 0, i = 0, j = 0, flag = 0;
	float aux = 0.0;
	char *auxstr = (char*)malloc(sizeof(char) * 5);

	if (number < 0.0)
	{
		flag = 1;
		number *= -1;
	}

	temp = number;
	aux = number - temp;

	if (aux != 0.0)
	{
		while (temp != 0)
		{
			auxstr[i] = (temp % 10) + '0';
			temp = temp / 10;
			i++;
		}

		if (flag == 1)
			auxstr[i++] = '-';

		auxstr[i] = '\0';

		auxstr = reverseString(auxstr, i);
		

		for (; j < i; j++)
			str[j] = auxstr[j];

		str[j] = '.';
		j++;

		temp = aux * (power(10, afterdecimal));
		i = 0;

		while (temp != 0)
		{
			auxstr[i] = (temp % 10) + '0';
			temp = temp / 10;
			i++;
		}
		auxstr[i] = '\0';

		auxstr = reverseString(auxstr, i);
		

		for (i = 0; auxstr[i] != '\0'; i++, j++)
			str[j] = auxstr[i];

		str[j] = '\0';
	}
	else
	{
		while (temp != 0)
		{
			auxstr[i] = (temp % 10) + '0';
			temp = temp / 10;
			i++;
		}

		if (flag == 1)
			auxstr[i++] = '-';

		auxstr[i] = '\0';

		auxstr = reverseString(auxstr, i);
		

		for (j = 0; auxstr[j] != '\0'; j++)
			str[j] = auxstr[j];

		str[j] = '\0';
	}
}
