#include "../includes/philosophers.h"

char *return_message(int type)
{
    if (type == 1)
        return (" is eating\n");
    else if (type == 2)
        return (" is sleeping\n");
    else if (type == 3)
        return (" has taken a fork\n");
    else if (type == 2)
        return (" is thinking\n");
    else
        return (" died\n");
}