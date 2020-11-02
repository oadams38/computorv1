#ifndef COMPUTOR_H
# define COMPUTOR_H

# include "libft.h"

int         check_correct_input(char *argv);
void        compute_and_print(char *poly);
int         is_math_symb(char c);
int         is_parenthesis(char c);

#endif