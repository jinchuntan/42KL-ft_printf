/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:17:43 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 18:57:18 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/*
Function:
Print a given string to standard output and return the total number of
characters printed.

Input:
str: A pointer to a string (char*)

Output:
c: An integer value (int)

Explanation:
1. Initialize the variable 'c' to 0.
2. If the input string is NULL, set the string pointer to point to a 
string literal "(null)".
3. Enter a while loop that iterates over each character in the string.
4. For each character, write the character to standard output using 
the write() function.
5. The write() function returns the number of bytes written 
(in this case, 1 byte for each character). Add the integer value returned 
by write() to the existing value of 'c'.
6. Finally, return the integer value 'c', which represents the total 
number of characters printed as a result of calling the function.
*/

int	ft_format_specifier_string(char *str)
{
	int	c;

	c = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[c] != '\0')
	{
		c += write(1, &str[c], 1);
	}
	return (c);
}
