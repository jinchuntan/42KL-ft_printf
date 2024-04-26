/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:49:28 by jintan            #+#    #+#             */
/*   Updated: 2023/05/04 18:37:47 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Header guard which prevents multiple inclusion of the same header file */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Declaring external libraries that are allowed */
/* Used for malloc and free built-in function */
# include <stdlib.h>

/* Used for the write built-in function */
# include <unistd.h>

/* Used for the variadic functions */
# include <stdarg.h>

/* Used for INT_MIN */
# include <limits.h>

/*
Defined Macros 
Basically just the preprocessor directives that allow for the subsituition 
of the code before actual compilation began.
So when we encounter macro in the code, the preprocessor replaces the
macro name with the corresponding value defined below
*/
# define BASE_10 "0123456789"
# define BASE_16_UPPERCASE "0123456789ABCDEF"
# define BASE_16_LOWERCASE "0123456789abcdef"

/* Utilities Functions */
char	*ft_strchr(const char *s, int c);
char	*ft_itoa_base(unsigned long long num, char *base);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

/* Formatting Functions */
int		ft_format_specifier_character(char c);
int		ft_format_specifier_decimal(int value);
int		ft_format_specifier_hexadecimal_lower(unsigned int value);
int		ft_format_specifier_hexadecimal_upper(unsigned int value);
int		ft_format_specifier_integer(int value);
int		ft_format_specifier_percent(char c);
int		ft_format_specifier_pointer(void *ptr);
int		ft_format_specifier_string(char *str);
int		ft_format_specifier_unsigned_decimal(unsigned int value);
int		ft_printf(const char *format, ...);

/* Marks the end of the conditional compilation that is guarded by #ifndef */
/* Basically signal the end of the block of code */
#endif
