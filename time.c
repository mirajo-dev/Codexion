#include "codexion.h"

long long get_time_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long long get_elapsed_ms(t_simulation *sim)
{
    return (get_time_ms() - sim->start_time);
}