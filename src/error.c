/*
** PERSONAL PROJECT, 2019
** connect4
** File description:
** connect 4 errors
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/connect4.h"

int err_out_of_range(int id)
{
    my_putstr("Error: this column is invalid or out of range\n");
    if (!id)
        my_putstr("Column: ");
    return (YES);
}

char *err_invalid_arg(void)
{
    my_putstr("Error: invalid character used to play.\n");
    return (NULL);
}
