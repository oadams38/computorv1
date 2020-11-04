#include "computor.h"

double  absolute(double n)
{
    return (n < 0 ? -n : n);
}

void    print_fact_1_n_2(int factor, double n, int printed, char unknown)
{
    if (printed == 1)
    {
        if (n < 0)
            ft_putstr(" - ");
        else
            ft_putstr(" + ");
        ft_putf(absolute(n));
    }
    else
        ft_putf(n);
    ft_putstr(" * ");
    ft_putchar(unknown);
    if (factor == 2)
        ft_putstr("^2");
}

void    print_reduced(double *factors)
{
    char    unknown;
    int     printed;

    printed = 0;
    unknown = (unsigned char)factors[3];
    ft_putstr("Reduced form: ");
    if (factors[0] >= 0.00001 || factors[0] <= -0.00001)
    {
        ft_putf(factors[0]);
        printed = 1;
    }
    if (factors[1] >= 0.00001 || factors[1] <= -0.00001)
    {
        print_fact_1_n_2(1, factors[1], printed, unknown);
        printed = 1;
    }
    if (factors[2] >= 0.00001 || factors[2] <= -0.00001)
    {
        print_fact_1_n_2(2, factors[2], printed, unknown);
        printed = 1;
    }
    ft_putstr(" = 0\n");
}

void    print_degree(double *factors)
{
    int i;

    i = 2;
    while (factors[i] <= 0.00001 && factors[i] >= -0.00001)
        i--;
    ft_putstr("Polynomial degree: ");
    ft_putnbr(i);
    ft_putchar('\n');
}

void    print_reduced_n_degree(double *factors)
{
    print_reduced(factors);
    print_degree(factors);
}