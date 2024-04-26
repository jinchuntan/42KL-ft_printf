/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 23:15:59 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 19:12:25 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library function header */
#include "../incs/ft_printf.h"

/*
Function:
Takes a character 'c' as input and returns an integer as output. 
The function checks whether the input character is a valid format specifier 
for the printf function in C programming language.

Input:
c: a character that is being checked to see if it is a valid format
specifier for printf

Output:
Either a 1 or a 0, depending on whether or not the character is a 
valid format specifier. 1 indicates that the character is a valid
format specifier. 0 indicates that it is not

Explanation:
The function first initializes two constant character pointers valid_args and 
found_args. 
The valid_args pointer holds a string of valid format specifiers that the 
function can handle, while the found_args pointer will be used to find 
if the input character c is a valid format specifier.

The ft_strchr function is used to search for the first occurrence of the 
character c in the string pointed to by valid_args. 
If the function finds the character c in the string, 
it returns a pointer to the first occurrence of the character in the string 
valid_args. 
If ft_strchr did not find the character in the string, 
it returns a NULL pointer.

If ft_strchr returns a NULL pointer, it means that the input character 
c is not a valid format specifier. 
In this case, the function returns 0 to indicate that the input character 
is not valid.

If ft_strchr returns a non-NULL pointer, it means that the input character c 
is a valid format specifier. 
In this case, the function returns 1 to indicate that the input character is 
valid.
*/

static int	ft_check_argument(int c)
{
	const char	*valid_args;
	const char	*found_args;

	valid_args = "cs pdiu%xX%";
	found_args = ft_strchr(valid_args, c);
	if (found_args == NULL)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

/*
Function:
Just determines which format specifier to use depending on the character
used (based on integer i) and call the corresponding format specifier
function with the appropriate arguments from va_list

Input:
i: representing a format specifier character
args: an argument of type va_list which is used to access the variable 
arguments in a function that receives a variable number of arguments.

Output:
c: The number of characters that were printed to the output stream
*/

static int	ft_format(int i, va_list args)
{
	int	c;

	c = 0;
	if (i == 'c')
		c = ft_format_specifier_character(va_arg(args, int));
	else if (i == 's')
		c = ft_format_specifier_string(va_arg(args, char *));
	else if (i == 'p')
		c = ft_format_specifier_pointer(va_arg(args, void *));
	else if (i == 'i' || i == 'd')
		c = ft_format_specifier_decimal(va_arg(args, int));
	else if (i == 'u')
		c = ft_format_specifier_unsigned_decimal(va_arg(args, unsigned long));
	else if (i == 'x')
		c = ft_format_specifier_hexadecimal_lower(va_arg(args, unsigned long));
	else if (i == 'X')
		c = ft_format_specifier_hexadecimal_upper(va_arg(args, unsigned long));
	else if (i == '%')
		c = ft_format_specifier_percent(i);
	else
		c = 0;
	return (c);
}

/*
Function:
The function loops through each character of the input string str, 
checks if it is not equal to the % character. 
If it is not, it prints the character to the standard output using the
write() function and increments the count c of printed characters.

Input:
str: a pointer to the string
args: an argument of type va_list which is used to access the variable 
arguments in a function that receives a variable number of arguments.

Output:
counter: counter of the printed characters

Explanation:
If the character is %, the function checks the next character in the string 
to see if it is a valid argument type using the ft_check_argument() function. 

If it is valid, the ft_format() function is called to format the argument, 
and the count of printed characters is incremented by the number of characters 
printed.

If it is not valid, the % character is printed to the standard output using 
the write() function, and the count c is incremented by one.
*/

static int	ft_parse_input(const char *str, va_list args)
{
	int	counter;
	int	index;

	index = 0;
	counter = 0;
	while (str[index])
	{
		if (str[index] != '%')
		{
			counter += write(1, &str[index], 1);
		}
		else if (str[index + 1] && str[index] == '%')
		{
			index++;
			if (ft_check_argument(str[index]))
				counter += ft_format(str[index], args);
			else if (str[index])
			{
				counter += write(1, &str[index], 1);
			}
		}
		index++;
	}
	return (counter);
}

/*
Function:
Format and print output to standard output using a variable 
number of arguments and a format string.

Input:
format: the format string (const char*)
va_list: variable number of arguments

Output:
counter: An integer value

Explanation:
It takes a format string and a variable number of arguments, 
then parses the input string and prints the formatted output

1. Function signature
The `ft_printf` function is defined with the function declaration
int ft_printf(const char* format, ...). 
It takes a constant character pointer,format as the 
format string, and a variable number of arguments indicated 
by the ellipsis ...

2. Variable declarations
const char* str: A constant character pointer that will be used to store 
a duplicate of the format string.
int counter: An integer initialized to 0 that will keep track of the 
number of characters printed.
va_list args: A variable of type va_list that will hold the variadic 
arguments passed to the function.

3. Duplicate the format string
str is assigned the result of ft_strdup(format), which 
duplicates the format string. 
If the duplication fails and str is NULL, the function returns -1, 
indicating an error.

4. Initialize the variadic arguments
va_start(args, format) initializes the args variable to handle 
the variable number 
of arguments that follow the format string.

5. Parse the input and print formatted output
The ft_parse_input function is called with the duplicated 
format string str and the args variable.
This function is responsible for parsing the input and 
printing the formatted output. 
The number of characters printed is added to the counter.

6. Clean up
va_end(args) is called to clean up the memory allocated 
for the variadic arguments. 
The memory allocated for the duplicated format string is 
freed using free((void*)str).

7. Return the counter
The function returns the value of counter, which is the number of 
characters printed by the ft_printf function.
*/

int	ft_printf(const char	*format, ...)
{
	const char	*str;
	int			counter;
	va_list		args;

	counter = 0;
	str = ft_strdup(format);
	if (str == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	counter += ft_parse_input(str, args);
	va_end(args);
	free((void *)str);
	return (counter);
}
