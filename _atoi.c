#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode or false if its not 
 * @info: structer of the  addresses is finite
 *
 * Return: 1 if interactive mode, 0 otherwise if its false ush over 
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter or maybe its otherwise 
 * @c: the char to check for all possible character entery thuse giving it a good reading 
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false or indefinite 
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character that is to be represented in a convertabel both
 *@c: The character to input either in form of OSk on the in beault system or physical 
 *Return: 1 if c is alphabetic, 0 otherwise continue it process 
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer value in case of small or long integer value
 *@s: the string to be converted to the integer value with respect to the memory space 
 *Return: 0 if no numbers in string therefore return the string to it else continue on the current path , converted number otherwise non converted numbers 
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
