/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier_character.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 00:16:04 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 18:39:22 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/*
Function:
The function takes in a single character 'c' as an argument and it's purpose 
is to print that character to the standard output using ft_putchar_fd()
which write a single character to a file descriptor (from libft)

Input:
c: A single character

Output:
Returns the number of characters that were printed

Explanation:
In case you ask me what the write function is
ssize_t write(int fd, const void *buf, size_t count);
fd: The file description that we want to write to
buf: A pointer to the data that we want to write
count: The number of bytes that we want to write

Returns the number of bytes written on success and -1 on failures. In
order to use 'write', need to use #include <unistd.h> header
*/

int	ft_format_specifier_character(char c)
{
	write(1, &c, 1);
	return (1);
}
