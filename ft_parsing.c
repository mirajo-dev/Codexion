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
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            return 0;
        else
            i++;
    }
    result = 0;
    while (nptr[i])
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    return (result);
}

int parse_argv(int ac, char **av, t_simulation *sim)
{
    int i;

    i = 1;
    if (ac != 9)
    {
        printf("Invalide parametre tokony ho 9\n");
        return (0);
    }
    if (!is_valide_scheduler(av[8]))
    {
        printf("Error: The scheduler name is incorrect;");
        printf(" it should be (fifo or edf).\n");
        return (0);
    }
    while (i <= 7)
    {
        if (!is_number(av[i]))
        {
            printf("Erro: Does not accept negative value​​(>=0)\n");
            return (0);
        }
        if (ft_atol(av[i]) > INT_MAX)
        {
            printf("mihoatra ny INT_MAX ilay valeur\n");
            return (0);
        }
        i++;
    }
    sim->number_of_coders = ft_atol(av[1]);
    sim->time_to_burnout = ft_atol(av[2]);
    sim->time_to_compile = ft_atol(av[3]);
    sim->time_to_debug = ft_atol(av[4]);
    sim->time_to_refactor = ft_atol(av[5]);
    sim->number_of_compiles_required = ft_atol(av[6]);
    sim->dongle_cooldown = ft_atol(av[7]);
    sim->scheduler = av[8];
    sim->simulation_over = 0;
    return (sim->number_of_coders > 0);
}
