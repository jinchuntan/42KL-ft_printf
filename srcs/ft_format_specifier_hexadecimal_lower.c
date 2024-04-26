/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier_hexadecimal_lowercase.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:28:49 by jintan            #+#    #+#             */
/*   Updated: 2023/04/30 23:28:49 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/*
Function:
Formats a given unsigned integer value into a string representation of its 
hexadecimal value (lowercase) and prints a hexadecimal number in lowercase
(return the total number of character printed)

Input:
value: An unsigned integer value (unsigned int)

Output:
c: An integer value (int)

Explanation:
Basically converts the unsigned integer value to a hexadecimal string in 
lowercase and stores it in the 'str' variable
1. Take an unsigned integer value as its input.
2. Convert the input value to a string representation of the number in 
hexadecimal base (BASE_16_LOWERCASE) using the ft_itoa_base() function.
3. Store the resulting hexadecimal string in the 'str' variable.
4. Call the ft_format_specifier_string() function with the 'str' 
variable as its input and store the integer value returned in the variable 'c'.
5. Free the memory used by the 'str' variable using the free() function.
6. Return the integer value 'c', which represents the total number of 
characters printed as a result of calling the function.
*/

int	ft_format_specifier_hexadecimal_lower(unsigned int value)
{
	int		c;
	char	*str;

	str = ft_itoa_base(value, BASE_16_LOWERCASE);
	c = ft_format_specifier_string(str);
	free(str);
	return (c);
}
