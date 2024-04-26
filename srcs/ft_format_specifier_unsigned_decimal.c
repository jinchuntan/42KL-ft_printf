/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier_unsigned_decimal.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:31:00 by jintan            #+#    #+#             */
/*   Updated: 2023/04/30 23:31:00 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/*
Function:
Format a given unsigned integer value into a string representation of the 
number in base 10, print the resulting string to standard output, and return 
the total number of characters printed.

Input:
value: An unsigned integer value

Output:
c: An integer value (int)

Explanation:
1. Convert the input unsigned integer value to a string representation of 
the number in base 10 using the ft_itoa_base() function.
2. Store the resulting string in the 'str' variable.
3. Call the ft_format_specifier_string() function with the 'str' variable as 
its input and store the integer value returned in the variable 'c'.
4. The ft_format_specifier_string() function prints the string to standard 
output and returns the number of characters printed.
5. Free the memory used by the 'str' variable using the free() function.
6. Return the integer value 'c', which represents the total number of 
characters printed as a result of calling the function.
*/

int	ft_format_specifier_unsigned_decimal(unsigned int value)
{
	int		c;
	char	*str;

	str = ft_itoa_base(value, BASE_10);
	c = ft_format_specifier_string(str);
	free(str);
	return (c);
}
