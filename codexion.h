#ifndef codexin_h
# define codexin_h

# include <stdint.h>
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_simulation
{
    int         number_of_coders;
    long long   time_to_burnout;
    long long   time_to_compile;
    long long   time_to_debug;
    long long   time_to_refactor;
    int         number_of_compiles_required;
    long long   dongle_cooldown;
    char        *scheduler;
    long long   start_time;//heur de debut de la simulaitoion, en millisecondes.
    int         simulation_over;//indique si la simulation s'arreter.
}   t_simulation;

typedef struct s_dongle
{
    int         id;//identifiant du dongle
    int         is_available;//indique si la dongle est disponible
    long long   available_at;//Heure à partir de laquelle le dongle peut être réutilisé après son cooldown.
}   t_dongle;

typedef struct s_coder
{
    int             id;//Le numéro du coder, compris entre 1 et number_of_coders.
    int             compile_count;//Le nombre de compilations terminées par ce coder.
    long long       last_compile_start;//L'heure de début de sa dernière compilation, exprimée en millisecondes depuis le début de la simulation.
    long long       deadline;//L'échéance de burnout calculée pour ce coder :
    int             is_compiling;//Indique si le coder est en train de compiler.
    int             has_burned_out;//Indique si le coder a subi un burnout.
    t_dongle        *left_dongle;//Ce sont des pointeurs vers les deux dongles voisins du coder.
    t_dongle        *right_dongle;
    t_simulation    *sim;//C'est un pointeur vers la simulation à laquelle appartient le coder.
}   t_coder;

int parse_argv(int ac, char ** av);

#endif