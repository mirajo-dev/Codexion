#include "codexion.h"

int main(int ac, char **av)
{
    if(!parse_argv(ac, av))
    {
        printf("Error: invalid arguments\n");
        return (1);
    }
    printf("Arguments syntax is valid\n");
    return (0);
}