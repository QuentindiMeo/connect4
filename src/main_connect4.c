/*
** PERSONAL PROJECT, 2019
** connecr4
** File description:
** main connect 4
*/

#include <stdlib.h>
#include "../include/connect4.h"
#include "../include/my.h"

static int help(void)
{
    my_putstr("\n\tWelcome to Connect 4\n\n \033[1mUSAGE\033[0m\n\t./connect4 "
    "[\033[4mOPTION\033[0m]\n\n \033[1mDESCRIPTION\033[0m\n\tThis game is made"
    " of a 7x6  grid where you play against one another.\n\tThe goal is to mak"
    "e a line of four  while getting your opponent away\n\tfrom doing it thems"
    "elf.    By default, Player 1's pieces will be \033[1mX\033[0ms,\n\tand Pl"
    "ayer 2's pieces will be \033[1mO\033[0ms.\n\n\t\033[1m-1\033[0m \033[4mPI"
    "ECE\033[0m, \033[1m--p1\033[0m=\033[4mPIECE\033[0m\n\t\033[1m-2\033[0m "
    "\033[4mPIECE\033[0m, \033[1m--p2\033[0m=\033[4mPIECE\033[0m\n\t\tChange t"
    "he players' pieces. \033[4mPIECE\033[0m  has  to  be  a  printable\n\t\tc"
    "haracter and it can't be a space (' ') or a dot ('.').\n\n\t\033[1m--name"
    "s\033[0m\n\t\tMake the program ask for two names to use as player names."
    "\n\n\t\033[1m-h\033[0m, \033[1m--help\033[0m\n\t\tDisplay this help.\n\n "
    "  \033[1mExit status:\033[0m\n\t0\tif the game ended with a draw or the g"
    "ame was quit (CTRL+D),\n\t1\tif the game ended and Player 1 won,\n\t2\tif"
    " the game ended and Player 2 won,\n\t84\tif the program ended with an err"
    "or.\n\n \033[1mAUTHOR\033[0m\n\tWritten by Quentin di Meo.\n\n \033[1mREP"
    "ORTING BUGS\033[0m\n\tReport any bug or functioning error to <quentin.di-"
    "meo@epitech.eu>\n\n");
    return (SUCCESS);
}

static int print_winner(int id, data *game)
{
    if (!id)
        return (my_putstr("\nIt's a draw!!\n") ? W_DRAW : W_DRAW);
    if (id == PLAYER1) {
        my_putchar('\n');
        my_putstr(game->name1);
        my_putstr(" wins!!\n");
        return (W_PLAYER1);
    }
    if (id == PLAYER2) {
        my_putchar('\n');
        my_putstr(game->name2);
        my_putstr(" wins!!\n");
        return (W_PLAYER2);
    }
    if (id == END_OF_FILE || id == END_OF_FILE2) {
        my_putstr("\nYou quit the game.\n");
        return (id == END_OF_FILE ? SUCCESS : END_OF_FILE);
    }
    return (FAILURE);
}

static int main_tictactoe(int ac, char **av, data *game)
{
    int ret_v;
    int winner;

    setup(&game);
    ret_v = get_parameters(ac, av, game);
    if (ret_v == FAILURE || ret_v == END_OF_FILE2)
        return (ret_v);
    if (ret_v == END_OF_FILE)
        return ((freer(game)) ? END_OF_FILE : END_OF_FILE);
    initial_print(game);
    for (int i = 0; i < HEIGHT_BOARD; i++)
        my_putstr(game->board[i]);
    winner = game_loop(game);
    if (winner == END_OF_FILE || winner == DRAW)
        return ((winner == END_OF_FILE) ? END_OF_FILE : W_DRAW);
    return (winner == PLAYER1 ? W_PLAYER1 : W_PLAYER2);
}

int main(int ac, char **av)
{
    int ret_v;
    data *game = NULL;

    if (ac == 2 &&
        (my_str_isequal(av[1], "-h") || my_str_isequal(av[1], "--help")))
        return (help());
    game = mallocator();
    ret_v = main_tictactoe(ac, av, game);
    ret_v = print_winner(ret_v, game);
    if (ret_v != END_OF_FILE)
        freer(game);
    return ((ret_v == END_OF_FILE) ? SUCCESS : ret_v);
}
