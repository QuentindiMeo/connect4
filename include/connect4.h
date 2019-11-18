/*
** PERSONAL PROJECT, 2019
** connect4
** File description:
** connect 4 header
*/

#ifndef CONNECT4_H_
#define CONNECT4_H_

struct data {
    char **board;
    char p1;
    char p2;
    int played_y;
    char *name1;
    char *name2;
};
typedef struct data data;

typedef enum {
    P1 = 'X',
    P2 = 'O',
    HEIGHT_BOARD = 6 + 2,
    LENGTH_BOARD = 7 + 2,
    EMP = '.',
} default_tictactoe_t;

typedef enum {
    DRAW = 0,
    PLAYER1 = 1,
    PLAYER2 = 2,
    W_DRAW = 0,
    W_PLAYER1 = 1,
    W_PLAYER2 = 2,
    END_OF_FILE2 = -2,
} return_values_tictactoe_t;

int err_out_of_range(int id);
char *err_invalid_arg(void);

int get_x(data *game);
int check_played_y(data *game);

int is_win(data *game);
int is_there_any_hole_left(data *game);
int switch_turn(int id);
int game_loop(data *game);

char *get_names(data **game);
int get_parameters(int ac, char **av, data *game);
void initial_print(data *game);
void setup(data **game);

int quit(char *to_be_freed);
data *freer(data *game);
data *mallocator(void);

#endif
