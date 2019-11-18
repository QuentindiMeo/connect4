/*
** PERSONAL PROJECT, 2019
** connect4
** File description:
** connect 4 detectors 2
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/connect4.h"
#include "../include/my.h"

int get_x(data *game)
{
    for (int x = HEIGHT_BOARD - 2; x; x--)
        if (game->board[x][game->played_y] == EMP)
            return (x);
    return (FAILURE);
}

int check_played_y(data *game)
{
    for (int x = 1; x < HEIGHT_BOARD - 1; x++)
        if (game->board[x][game->played_y] == EMP)
            return (SUCCESS);
    my_putstr("Error: this row is already full\n");
    return (FAILURE);
}
