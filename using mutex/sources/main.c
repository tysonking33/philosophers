#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
    t_rules *gen;
    gen = (t_rules *)malloc(sizeof(t_rules));
    if (!gen)
        return 0;


    //initalise rules
    if (init_all(gen, argc, argv) != 1)
        return 0;




    //initalise threads
    start_threads(gen);

    //pthread lock

    //pthread unlock
}