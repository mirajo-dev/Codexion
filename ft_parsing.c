#include "codexion.h"

static bool is_number(char *nbr)
{
    int i;

    i = 0;
    if (!nbr[i])
        return (false);
    if (nbr[i] == '+')
        i++;
    while (nbr[i])
    {
        if (nbr[i] < '0' || nbr[i] > '9')
            return (false);
        i++;
    }
    return (true);
}

static bool is_valide_scheduler(char *scheduler)
{
    if (strcmp(scheduler, "fifo") == 0)
        return (true);
    else if (strcmp(scheduler, "edf") == 0)
        return (true);
    return (false);
}

static long ft_atol(char *nptr)
{
    long result;
    int i;

    i = 0;
    if (!*nptr)
        return 0;
    if (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            return 0;
    }
    result = 0;
    while (nptr[i])
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    return (result);
}

int parse_argv(int ac, char **av)
{
    int i;

    i = 1;
    if (ac != 9)
        return (0);
    while (i <= 7)
    {
        if (!is_number(av[i]))
            return (0);
        i++;
    }
    if (i == 8)
    {
        if (!is_valide_scheduler(av[i]))
            return (0);
    }
    return (1);
}
