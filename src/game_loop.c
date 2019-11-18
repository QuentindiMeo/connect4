/*
** PERSONAL PROJECT, 2019
** connect4
** File description:
** connect 4 game loop
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/connect4.h"
#include "../include/my.h"

static void place_cursor(data **game)
{
    int i = 0;

    for (; i < (*game)->played_y; i++)
        (*game)->board[0][i] = ' ';
    (*game)->board[0][i] = 'v';
    (*game)->board[0][i + 1] = '\n';    
}

static void play(data **game, uchar whose_turn)
{
    (*game)->board[get_x(*game)][(*game)->played_y] =
        (whose_turn == PLAYER1 ? (*game)->p1 : (*game)->p2);
    my_putstr(whose_turn == PLAYER1 ? (*game)->name1 : (*game)->name2);
    my_putstr(" placed a piece on row ");
    my_putnbr((*game)->played_y);
    my_putstr("\n");
    place_cursor(game);
    for (uint i = 0; i < HEIGHT_BOARD; i++)
        my_putstr((*game)->board[i]);
    for (uint i = 0; i < LENGTH_BOARD; i++)
        (*game)->board[0][i] = 0;
}

static int get_y(data **game)
{
    char *entry = NULL;
    size_t buff = 0;
    int ret_v;
    int pos[7] = {1, 2, 3, 4, 5, 6, 7};

    (*game)->played_y = 0;
    my_putstr("Row: ");
    while (!(*game)->played_y) {
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (quit(entry));
        (*game)->played_y = my_getnbr(entry);
        if (!my_int_isinarray(pos, (*game)->played_y, 7) ||
            (*game)->played_y == 0) {
            ret_v = err_out_of_range(0);
            (*game)->played_y = 0;
        }
    }
    free(entry);
    return (SUCCESS);
}

static int user_play(data *game, uchar whose_turn)
{
    int ret_v = SUCCESS;

    do {
        ret_v = get_y(&game);
    } while (ret_v != END_OF_FILE && check_played_y(game) == FAILURE);
    if (ret_v == END_OF_FILE)
        return (END_OF_FILE);
    play(&game, whose_turn);
    return (SUCCESS);
}

int game_loop(data *game)
{
    uchar whose_turn = PLAYER2;
    int ret_v;

    for (uchar over = FALSE; over != TRUE;) {
        whose_turn = switch_turn(whose_turn);
        my_putstr("\n\nIt's ");
        my_putstr(whose_turn == PLAYER1 ? game->name1 : game->name2);
        my_putstr("'s turn:\n");
        ret_v = user_play(game, whose_turn);
        if (ret_v == END_OF_FILE)
            return (END_OF_FILE);
        if (!(is_there_any_hole_left(game) == YES && !is_win(game)))
            over = TRUE;
    }
    if (!is_win(game))
        whose_turn = DRAW;
    return (whose_turn);
}
