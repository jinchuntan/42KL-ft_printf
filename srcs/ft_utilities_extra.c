/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:20:38 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 19:32:00 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/* Used for calloc */
#include <stdint.h>

/* 
Function:
Used to set a block of memory to zero

Input:
dst - An existing object that you want to fill with zeroes.
n - the number of bytes to be filled

Output:
sets the first n bytes of thememory area starting at dest to zero/NULL.

Explanation:
The function sets the first part of an object to null bytes 
bzero() function erases the data in the n bytes of the memory starting at the 
location pointed to by s, by writing zeros (bytescontaining '\0') to that area

bzer0() function in general has been deprecated in favour of 'memset'

size_t is an unsigned integer data type that is guaranteed to be 
able to hold the size of any object that can be created in C. 
It is commonly used in C programming to represent sizes 
and counts of objects. 

Basically just iterates over the memory area, setting each byte to the null
character
*/

static void	ft_bzero(void *dest, size_t n)
{
	size_t	i;
	char	*pointer_dest;

	i = 0;
	pointer_dest = dest;
	while (i < n)
	{
		pointer_dest[i] = '\0';
		i++;
	}
}

/* 
Function:
The calloc function allocates a block of memory for an array of count 
elements, each of which has a size of size bytes. 
It initializes the memory block to zero.

Input:
size_t count: The number of elements to allocate memory for.
size_t size: The size of each element in bytes

Output:
Pointer to the allocated memory block that has been initialised with zeros or
NULL if the allocation fails.

Explanation & Thought Process:
size_t is an unsigned integer type used for representing the size of objects
in memory. Commonly used in functions and data structures that deal with 
memory allocation and manipulation.

The declaration in this function is to ensure that the function is consistent
with other memory-related functions and can handle objects of any size. It
also helps us to avoid issues related to integer overlfow and underflow.
*/

static void	*ft_calloc(size_t count, size_t size)
{
	void		*result;
	size_t		total_size;

	total_size = count * size;
	result = malloc(total_size);
	if (size != 0 && count > SIZE_MAX / size)
	{
		return (NULL);
	}
	if (result == NULL)
	{
		return (NULL);
	}
	ft_bzero(result, total_size);
	return (result);
}

/*
Function:
Takes an unsigned long long integer num and a character array base
which represents the base of the number system. It will return the 
length of the string representation of num in the given base

Input:
num: unsigned long long integer
base: a character array

Output:
len: The length of the string

Explanation:
1) The function will find the length of the string (base string) 
first.
2) The while loop will then keep on dividing num by base len until
num is less than base len. Len will of course be incremented in the
process.
*/

static size_t	ft_base_len(unsigned long long num, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (num >= base_len)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

/*
Function:
Takes an unsigned long long integer, num and a base in the form
of a character array (base). It will then convert the given number
to a string representation in the given base and returns a newly
allocated string.

Input:
num: unsigned long long integer
base: a character array

Output:
str: A pointer to the newly allocated string representing the 
input unsigned integer (num) converted to a string with the 
gievn 'base'

Explanation:
1) The function first calculates the length of the resulting string 
by calling the ft_base_len function, passing in num and base.
2) Memory will then be allocated and it will check whether memory
allocation is successful or not (num_len + 1) is to include the
null terminator
3) It then enters a loop that iterates over the length of the string. 
Inside the loop, it decrements the length of the string by one, 
sets the value at the current position of the string to the character 
in the base array corresponding to the remainder of num divided by the 
length of the base, and then divides num by the length of the base. 
This process is repeated until the length of the string is zero.
4) Then it returns the pointer to the string
*/
char	*ft_itoa_base(unsigned long long num, char *base)
{
	int		num_len;
	int		base_len;
	char	*str;

	num_len = ft_base_len(num, base);
	base_len = ft_strlen(base);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}
