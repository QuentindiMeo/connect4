/*
** PERSONAL PROJECT, 2019
** connect4
** File description:
** connect 4 detectors
*/

#include "../include/my.h"
#include "../include/connect4.h"

static int someone_won(char **board, char p)
{
    for (int x = 1; x < HEIGHT_BOARD - 1; x++)
        for (int y = 1; y <= 4; y++)
            if (board[x][y] == p && board[x][y + 1] == p &&
                board[x][y + 2] == p && board[x][y + 3] == p)
                return (TRUE);
    for (int y = 1; y < LENGTH_BOARD - 1; y++)
        for (int x = 1; x <= 3; x++)
            if (board[x][y] == p && board[x + 1][y] == p &&
                board[x + 2][y] == p && board[x + 3][y] == p)
                return (TRUE);
    for (int y = 1; y <= 4; y++)
        for (int x = 1; x <= 3; x++)
            if (board[x][y] == p && board[x + 1][y + 1] == p &&
                board[x + 2][y + 2] == p && board[x + 3][y + 3] == p)
                return (TRUE);
    for (int y = 4; y < LENGTH_BOARD - 1; y++)
        for (int x = 1; x <= 3; x++)
            if (board[x][y] == p && board[x + 1][y - 1] == p &&
                board[x + 2][y - 2] == p && board[x + 3][y - 3] == p)
                return (TRUE);
    return (FALSE);
}

int is_win(data *game)
{
    if (someone_won(game->board, game->p1) ||
        someone_won(game->board, game->p2))
        return (TRUE);
    return (FALSE);
}

static int is_there_any_hole_left_line(char *line)
{
    for (int x = 0; x < LENGTH_BOARD - 1; x++)
        if (line[x] == EMP)
            return (YES);
    return (NO);
}

int is_there_any_hole_left(data *game)
{
    for (int y = 0; y < HEIGHT_BOARD - 1; y++)
        if (is_there_any_hole_left_line(game->board[y]))
            return (YES);
    return (NO);
}

int switch_turn(int id)
{
    int save = id;

    if (save == PLAYER1)
        id = PLAYER2;
    if (save == PLAYER2)
        id = PLAYER1;
    return (id);
}
