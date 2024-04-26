/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:33:55 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 19:31:30 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/* Used for calloc */
#include <stdint.h>

/* 
Basically this is just the function that I have copied and paste into
this source file from my libft project 
*/

/*
Function: 
String Character
Used to search for the first occurrence of a specified character in a given
string.

Input:
Takes two arguments 
Characters are represented as integers, so the function can be called 
with a character literal as the second argument.
const char s: a pointer to the string to be searched
int c: the character to be searched for

Output:
Returns a pointer to the first occurence of the character 'c' in the string
's' or NULL if the character is not found

Explanation:
We iterate through each character in the string, compares each character to
the character,c and return a pointer to the current character if they match.
If no character c is found, return NULL
*/

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == s[i])
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

/*
Function: 
Counting the length of the string

Input:
str: A pointer to a string

Output:
The counter (length of the string)
*/

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/*
Function: 
strdup: String Duplicate

Input:
s: The pointer to the string,s 

Output:
dup_str : returns the duplicated string
*/

char	*ft_strdup(const char *s)
{
	char	*dup_str;
	size_t	len;

	len = ft_strlen(s);
	dup_str = malloc((len + 1) * sizeof(char));
	if (dup_str == NULL)
	{
		return (NULL);
	}
	len = 0;
	while (s[len])
	{
		dup_str[len] = s[len];
		len++;
	}
	dup_str[len] = '\0';
	return (dup_str);
}

/*
Function:
Takes two pointer to the input string (s1 and s2) and concatenates them
to form a new string

Input:
s1: A pointer to the first string
s2: A pointer to the second string

Output:
str: The concatenated string

Explanation:
Basically just concatenate two strings together
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
