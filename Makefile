# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 19:32:30 by jintan            #+#    #+#              #
#    Updated: 2023/04/12 19:32:30 by jintan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Defining the name of the static library
NAME = libftprintf.a

# Compiler used
CC = cc

# Compiler flags used during compilation
CFLAGS = -Wall -Werror -Wextra -I./incs

# Used to create a static library
AR = ar rcs

# Removing files and directories
RM = rm -rf

# The list of source files to be compiled
SRCS =   srcs/ft_format_specifier_character.c\
		 srcs/ft_format_specifier_decimal.c\
		 srcs/ft_format_specifier_hexadecimal_lower.c\
		 srcs/ft_format_specifier_hexadecimal_upper.c\
		 srcs/ft_format_specifier_integer.c\
		 srcs/ft_format_specifier_percent.c\
		 srcs/ft_format_specifier_pointer.c\
		 srcs/ft_format_specifier_string.c\
		 srcs/ft_format_specifier_unsigned_decimal.c\
		 srcs/ft_printf.c\
		 srcs/ft_utilities_extra.c\
		 srcs/ft_utilities.c

# Replaces the .c file extension with .o file extension for each
# source files
OBJS = $(SRCS:.c=.o)

# Specifies how to create object files from C source files. 
# It compiles each source file with the specified compiler and flags, 
# creating an object file with the same name.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# The default target (basically if you just put make, this command will
# be executed)
all: $(NAME)

# Creating the static library
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Removes the object files using the RM command
clean:
	$(RM) $(OBJS)

# Depends on the 'clean' target and additionally removes the
# static library using RM COmmand
fclean: clean
	$(RM) $(NAME)

# Cleans up the build and the all target, which rebuilds the project
# from scratch
re: fclean all

# Indicates that the specified targets are not associated with the files
# Basically prevents the targets from being confused with files that have
# the same name
.PHONY: re all clean fclean