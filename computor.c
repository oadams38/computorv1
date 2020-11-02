#include "computor.h"

int     main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (check_correct_input(argv[1]))
        {
            compute_and_print(argv[1]);
            return (0);
        }
    }
    ft_putstr("error\n");
    return (0);
}