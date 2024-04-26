/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier_pointer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:18:03 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 18:56:44 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/*
Function:
A static function that takes a pointer to a string as it's input and count
the number of format specifier characters in a given string.

Input:
str: A pointer to a string (char*)

Output:
c: An integer value (int)

Explanation:
1) Calls the function ft_format_specifier_string() with the same string pointer 
as its argument.

The ft_format_specifier_string() function takes the input string and looks 
for any format specifier characters (such as '%') in the string, 
returning the number of format specifier characters found.

The ft_print_prefix() function then returns the integer value returned by the 
ft_format_specifier_string() function. 
This integer value represents the number of format specifier characters 
found in the input string.
*/

static int	ft_print_prefix(char *str)
{
	int	c;

	c = ft_format_specifier_string(str);
	return (c);
}

/*
Function:
format a given pointer into a string representation of its hexadecimal 
address, with the prefix "0x", and return the total number of characters 
printed as a result of the formatting.

Input:
ptr: A pointer to a void type (void*)

Output:
c: An integer value (int)

Explanation:
1) Checks whether the input pointer is NULL or not
2) If not, convert the pointer to an unsigned long integer value and stores
it (in variable address)
3) Calls the ft_print_prefix function with the string "0x" as input and store 
the integer value returned in the variable 'c'
4) Converts the address values to a hexadecimal string
5) Calls the ft_format_specifier string and add the integer value (returned)
to the existing value of 'c'
6) Frees the memory used
*/

int	ft_format_specifier_pointer(void *ptr)
{
	int				c;
	unsigned long	address;
	char			*str;

	if (ptr == NULL)
	{
		address = 0;
	}
	else
	{
		address = (unsigned long)ptr;
	}
	c = ft_print_prefix("0x");
	str = ft_itoa_base(address, BASE_16_LOWERCASE);
	c += ft_format_specifier_string(str);
	free(str);
	return (c);
}
