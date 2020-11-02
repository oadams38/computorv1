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
            if (unknown == ' ')
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
            if (wasmath && is_math_symb(argv[i]))
                return (-1);
            wasmath = is_math_symb(argv[i]);
        }
    }
    return (wasmath == -1);
}

int     check_power(char *argv)
{
    int     i;
    int     tmp_j;
    int     tmp_k;

    i = -1;
    while (argv[++i])
    {
        if (argv[i] == '^')
        {
            tmp_j = i;
            while (tmp_j - 1 >= 0
                    && is_parenthesis(argv[tmp_j - 1]) != 0)
                tmp_j--;
            tmp_k = i;
            while (argv[tmp_k + 1] != '\0'
                    && is_parenthesis(argv[tmp_k + 1]) != 0)
                tmp_k++;
            if (!(ft_isdigit(argv[tmp_j]) && ft_isdigit(argv[tmp_k])))
                return (-1);
            if (ft_atoi(&argv[i + 1]) > 2)
                return (-1);
        }
    }
    return (1);
}

int     check_correct_input(char *argv)
{
    return (check_par_digit_mathsymb(argv) == 1
            && check_unknown_n_equal_nb(argv) == 1
            && check_mathsymb_position(argv) == 1
            && check_power(argv) == 1);
    //check nbs not too high. itoa -> if = len -> strcmp
}