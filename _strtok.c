#include "monty.h"


/**
 * _strtok - custom strtok function
 * @s: pointer to the string
 * @delim: pointer to delimiters
 *
 * Return: a pointer to the next token or
 *         NULL if there is no more token
 */
char *_strtok(char *s, const char *delim)
{
	static char *last_token;
	char *token;

	/*If s is NULL, continue from the last token*/
	if (s == NULL)
		s = last_token;
	else
		last_token = s;

	/*Skip leading delimiters*/
	s += strspn(s, delim);

	/*If we've reached the end, return NULL*/
	if (*s == '\0')
		return (NULL);

	/*Find the end of the token*/
	token = s;
	s += strcspn(s, delim);

	/*Terminate the token and update last_token*/
	if (*s != '\0')
	{
		*s = '\0';
		last_token = s + 1;
	}
	else
	{
		last_token = NULL;
	}

	return (token);
}
