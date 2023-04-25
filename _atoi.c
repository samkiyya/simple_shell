#include "simple_shell.h"

/**
 * inter_active - returns true if simple_shell is inter_active mode
 * @info: struct address
 *
 * Return: 1 if inter_active mode, 0 otherwise
 */
int inter_active(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_dem - checks if character is a delimeter
 * @c: the char to check
 * @dem: the demeter string
 * Return: 1 if true, 0 if not True
 */
int is_dem(char c, char *dem)
{
	while (*dem)
		if (*dem++ == c)
			return (1);
	return (0);
}

/**
 * _isaphabet - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isaphabet(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
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
