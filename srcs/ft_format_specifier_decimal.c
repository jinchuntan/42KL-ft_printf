/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier_decimal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:18:28 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 18:48:58 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/*
Function:
Convert a given integer value to a string representation of the number, taking 
into account the possibility of negative values and the minimum value of an 
integer. 

Input:
num: a pointer to an integer value 

Output:
A pointer to a character array

Explanation:
The function ft_int_to_str() takes a pointer to an integer value as its input. 
The function first checks if the input integer value is equal to the minimum 
value of an integer (INT_MIN). 
If it is, the function returns a pointer to a string literal "-2147483648" 
using the ft_strdup() function. 
This is because the absolute value of INT_MIN cannot be represented as a 
positive integer due to the way two's complement representation works.

If the input integer value is not equal to INT_MIN, we checks if 
the integer value is negative. If it is, we will first negates the value 
by multiplying it by -1. 

We will then converts the absolute value of the integer to a string 
representation of the number using the ft_itoa_base() function, 
which takes the integer value and the specified base (BASE_10 in this case) 
and returns a pointer to a character array.

We then joins the resulting string with a '-' character using the 
ft_strjoin() function to create a negative representation of the integer 
and returns a pointer to the resulting character array. 
The memory used by the original string representation of the absolute value 
of the integer is freed using the free() function.

If the input integer value is not negative, we simply converts the 
integer value to a string representation using the ft_itoa_base() function 
and returns a pointer to the resulting character array.
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
Takes an integer as it's input and format a given integer value into a string
representation if the number and return the total number of characters 
printed

Input:
value: An integer value (int)

Output:
c: An integer value (int)

Explanation:
1) Convert the intergre value to a string representation of the number
2) Call the ft_format_specifier_string which takes a string and returns
out the total number of characters
3) Frees the memory
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
