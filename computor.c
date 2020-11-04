#include "computor.h"

int     main(int argc, char **argv)
{
    char    *str;
    double  *factors;

    if (argc == 2)
    {
        str = ft_strrmchar(argv[1], ' ');
        if (check_correct_input(str))
        {
            factors = get_factors(str);
            print_reduced_n_degree(factors);
            //solve(factors);
            free((void*)str);
            free((void*)factors);
            return (0);
        }
        free((void*)str);
    }
    ft_putstr("error\n");
    return (0);
}