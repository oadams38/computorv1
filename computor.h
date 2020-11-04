#ifndef COMPUTOR_H
# define COMPUTOR_H

# include "libft.h"

int         check_correct_input(char *argv);
double      *get_factors(char *expression);
int         is_math_symb(char c);
int         is_parenthesis(char c);
void        print_reduced_n_degree(double *factors);

#endif