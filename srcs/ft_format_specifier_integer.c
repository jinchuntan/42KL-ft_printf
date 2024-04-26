/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier_integer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:19:10 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 18:54:40 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/*
Function:
convert a given integer value to a string representation of the number, 
taking into account the possibility of negative values and the minimum value 
of an integer. 

Input:
num: a pointer to an integer value (int*)

Output:
A pointer to a character array (char*)

Explanation:
1. Check if the input integer value is equal to the minimum value of an 
integer (INT_MIN).
2. If it is, return a pointer to a string literal "-2147483648" 
using the ft_strdup() function.
3. If the input integer value is not equal to INT_MIN, 
check if the integer value is negative.
4. If it is, first negate the value by multiplying it by -1.
5. Convert the absolute value of the integer to a string representation 
of the number using the ft_itoa_base() function.
6. Join the resulting string with a '-' character using the ft_strjoin() 
function to create a negative representation of the integer.
7. Return a pointer to the resulting character array.
8. Free the memory used by the original string representation of the 
absolute value of the integer using the free() function.
9. If the input integer value is not negative, simply convert the integer 
value to a string representation using the ft_itoa_base() function.
10. Return a pointer to the resulting character array.
*/

static char	*ft_int_to_str(int	*num)
{
	char	*str;
	char	*result;

	if (*num == INT_MIN)
	{
		return (ft_strdup("-2147483648"));
	}
	else
	{
		if (*num < 0)
		{
			*num = -*num;
			str = ft_itoa_base(*num, BASE_10);
			result = ft_strjoin("-", str);
			free(str);
			return (result);
		}
		else
		{
			return (ft_itoa_base(*num, BASE_10));
		}
	}
}

/*
Function:
format a given integer value into a string representation of the number, 
print the resulting string to standard output and return the total number 
of characters printed.

Input:
value: An integer value (int)

Output:
c: An integer value (int)

Explanation:
1. Call the ft_int_to_str() function with a pointer to the input integer 
value as its argument.
2. The ft_int_to_str() function converts the input integer to a string 
representation of the number and returns a pointer to the resulting 
character array.
3. Call the ft_format_specifier_string() function with the character 
array returned by ft_int_to_str() as its input and store the 
integer value returned in the variable 'c'.
4. The ft_format_specifier_string() function prints the string to standard 
output and returns the number of characters printed.
5. Free the memory used by the character array returned by ft_int_to_str() 
using the free() function.
6. Return the integer value 'c', which represents the total number of 
characters printed as a result of calling the function.
*/

int	ft_format_specifier_decimal(int value)
{
	char	*str;
	int		c;

	str = ft_int_to_str(&value);
	c = ft_format_specifier_string(str);
	free(str);
	return (c);
}
