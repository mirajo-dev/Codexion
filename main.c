#include "codexion.h"

int main(int ac, char **av)
{
    t_simulation sim;

    if(!parse_argv(ac, av, &sim))
        return (1);
    sim.start_time = get_time_ms();
    usleep(1000);
    printf("%lld ms\n", get_elapsed_ms(&sim));
    return (0);
}