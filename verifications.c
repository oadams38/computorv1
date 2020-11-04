#include "computor.h"

int     check_par_digit_mathsymb(char *argv)
{
    int     i;
    int     par;

    i = -1;
    par = 0;
    while (argv[++i])
    {
        par += is_parenthesis(argv[i]);
        if (par < 0)
            return (-1);
        if (!(ft_isdigit(argv[i]) || is_math_symb(argv[i])
                || argv[i] == '(' || argv[i] == ')'))
            return (-1);
        if (argv[i] == '(' && argv[i + 1] != '\0'
            && ! ft_isdigit(argv[i + 1]))
            return (-1);
        if (argv[i] == ')' && i - 1 >= 0
            && ! ft_isdigit(argv[i - 1]))
            return (-1);
    }
    return (1);
}

int     check_unknown_n_equal_nb(char *argv)
{
    int     i;
    char    unknown;
    int     equals;

    i = -1;
    equals = 0;
    unknown = ' ';
    while (argv[++i])
    {
        if (ft_isalpha(argv[i]))
        {
            if (unknown == ' ' || unknown == argv[i])
                unknown = argv[i];
            else
                return (-1);
        }
        if (argv[i] == '=')
            equals++;            
    }
    return (equals == 1);
}

int     check_mathsymb_position(char *argv)
{
    int     i;
    int     wasmath;

    i = -1;
    wasmath = 1;
    while (argv[++i])
    {
        if (argv[i] != '(' && argv[i] != ')')
        {
            if (wasmath == 1 && is_math_symb(argv[i]) == 1)
                return (-1);
            wasmath = is_math_symb(argv[i]);
        }
    }
    return (wasmath == -1);
}

int     check_power(char *argv)
{
    int     i;

    i = -1;
    while (argv[++i])
    {
        if (argv[i] == '^')
        {
            if (!ft_isalpha(argv[i - 1]) || !ft_isdigit(argv[i + 1]))
                return (-1);
            if (ft_atoi(&argv[i + 1]) > 2)
                return (-1);
        }
    }
    return (1);
}

int     check_correct_input(char *argv)
{
    if (check_par_digit_mathsymb(argv) != 1)
        ft_putstr("\nProblem at check_par_digit_mathsymb");
    if (check_unknown_n_equal_nb(argv) != 1)
        ft_putstr("\nProblem at check_unknown_n_equal_nb");
    if (check_mathsymb_position(argv) != 1)
        ft_putstr("\nProblem at check_mathsymb_position");
    if (check_power(argv) != 1)
        ft_putstr("\nProblem at check_power");

    return (check_par_digit_mathsymb(argv) == 1
            && check_unknown_n_equal_nb(argv) == 1
            && check_mathsymb_position(argv) == 1
            && check_power(argv) == 1);
}