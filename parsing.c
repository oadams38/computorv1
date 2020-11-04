#include "computor.h"

void        add_left_factors(double *factors, char *str)
{
    int     i;
    int     pow;

    i = ft_strfindc(str, '^');
    if (i == -1)
    {
        if (ft_strisnum(str))
            pow = 0;
        else
            pow = 1;
    }
    else
        pow = str[i + 1] - '0';
    factors[pow] += ft_atof(str);
}

void        sub_right_factors(double *factors, char *str)
{
    int     i;
    int     pow;

    i = ft_strfindc(str, '^');
    if (i == -1)
    {
        if (ft_strisnum(str))
            pow = 0;
        else
            pow = 1;
    }
    else
        pow = str[i + 1] - '0';
    factors[pow] -= ft_atof(str);
}

void        add_unknown(double *factors, char *str)
{
    int     i;

    i = -1;
    while (str[++i])
    {
        if (ft_isalpha(str[i]))
            factors[3] = (double)str[i];
    }
}

double      *get_factors(char *str)
{
    char    **left_right;
    char    **left;
    char    **right;
    double  *factors;
    int     i;

    str = ft_strreplace(ft_strreplace(str, "-", " -"), "+", " +");
    left_right = ft_strsplit(str, '=');
    left = ft_strsplit(left_right[0], ' ');
    right = ft_strsplit(left_right[1], ' ');
    factors = ft_memalloc(sizeof(double) * 4);
    i = -1;
    while (++i < 3)
        factors[i] = (double)0;
    i = -1;
    while (left[++i] != NULL)
        add_left_factors(factors, left[i]);
    i = -1;
    while (right[++i] != NULL)
        sub_right_factors(factors, right[i]);
    add_unknown(factors, str);
    ft_freetab(left);
    ft_freetab(right);
    return (factors);
}