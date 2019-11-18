/*
** PERSONAL PROJECT, 2019
** connect4
** File description:
** connect 4 setup
*/

#include <stdlib.h>
#include <getopt.h>
#include "../include/connect4.h"
#include "../include/my.h"

static int isok(char c)
{
    if (c < 33 || c == '.' || c > 126)
        return (FALSE);
    return (TRUE);
}

static char *do_switch(char c, char *optarg, data **game)
{
    switch (c) {
    case '1' :
        if (my_strlen(optarg) > 1 || !isok(*optarg))
            return (err_invalid_arg());
        (*game)->p1 = (*optarg);
        break;
    case '2' :
        if (my_strlen(optarg) > 1 || !isok(*optarg))
            return (err_invalid_arg());
        (*game)->p2 = (*optarg);
        break;
    case 'n' :
        return (get_names(game));
        break;
    case '?' :
        my_putstr("Try './connect4 --help' for more information.\n");
        return (NULL);
        break;
    }
    return ("-");
}

static struct option *set_longopts(void)
{
    struct option *longopts = malloc(sizeof(struct option) * 3);

    longopts[0].name = "p1";
    longopts[0].has_arg = 1;
    longopts[0].flag = NULL;
    longopts[0].val = '1';
    longopts[1].name = "p2";
    longopts[1].has_arg = 1;
    longopts[1].flag = NULL;
    longopts[1].val = '2';
    longopts[2].name = "names";
    longopts[2].has_arg = 0;
    longopts[2].flag = NULL;
    longopts[2].val = 'n';
    return (longopts);
}

int get_parameters(int ac, char **av, data *game)
{
    char c = 0;
    char *ret_v;
    struct option *longopts = set_longopts();

    do {
        c = getopt_long(ac, av, "1:2:", longopts, NULL);
        ret_v = do_switch(c, optarg, &game);
        if (ret_v == NULL) {
            free(longopts);
            return (FAILURE);
        } else if ((*ret_v) == 'n') {
            free(longopts);
            freer(game);
            return (END_OF_FILE2);
        }
    } while (c != END_OF_ARGS);
    free(longopts);
    return (SUCCESS);
}

void setup(data **game)
{
    for (int i = 1; i < HEIGHT_BOARD; i++)
        my_strcpy((*game)->board[i], "|.......|");
    my_strcpy((*game)->board[HEIGHT_BOARD - 1], "/-------\\");
    for (int i = 1; i <= HEIGHT_BOARD; i++) {
        (*game)->board[i][LENGTH_BOARD] = '\n';
        (*game)->board[i][LENGTH_BOARD + 1] = 0;
    }
    for (int i = 0; i < LENGTH_BOARD + 1; i++)
        (*game)->board[0][i] = 0;
    (*game)->p1 = P1;
    (*game)->p2 = P2;
    (*game)->played_y = 0;
    (*game)->name1 = my_strdup("Player 1");
    (*game)->name2 = my_strdup("Player 2");
}
