/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:20:34 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 18:55:41 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/*
Function:
Print the character '%' to standard output and return the total number of 
characters printed, which is always 1. 

Input:
c: A character value

Output:
the total number of character which is 1.
*/

int	ft_format_specifier_percent(char c)
{
	write(1, &c, 1);
	return (1);
}
