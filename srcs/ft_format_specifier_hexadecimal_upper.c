/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier_hexadecimal_uppercase.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:29:09 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 18:50:02 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/*
Function:
Formats a given unsigned integer value into a string representation of its 
hexadecimal value (uppercase) and prints a hexadecimal number in uppercase
(return the total number of character printed)

Input:
value: An unsigned integer value (unsigned int)

Output:
c: An integer value (int)

Explanation:
Same explanation as the format specifier hexadecimal lowercase function
*/

int	ft_format_specifier_hexadecimal_upper(unsigned int value)
{
	int		c;
	char	*str;

	str = ft_itoa_base(value, BASE_16_UPPERCASE);
	c = ft_format_specifier_string(str);
	free(str);
	return (c);
}
