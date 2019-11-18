/*
** PERSONAL PROJECT, 2019
** connect4
** File description:
** connect 4 setup 2
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/connect4.h"
#include "../include/my.h"

void initial_print(data *game)
{
    my_putstr(game->name1);
    my_putstr(": ");
    my_putchar(game->p1);
    my_putchar('\n');
    my_putstr(game->name2);
    my_putstr(": ");
    my_putchar(game->p2);
    my_putstr("\n\n");
}

static char *free_alt(char *s1)
{
    free(s1);
    return (NULL);
}

char *get_name2(data **game)
{
    char *entry = NULL;
    size_t buff = 0;

    for (int ret_v = 1; ret_v == 1;) {
        my_putstr("Enter Player 2's name: ");
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (free_alt(entry));
        free((*game)->name2);
        (*game)->name2 = my_cut_str(entry, 0, my_strlen(entry) - 2);
        if (my_str_isblank((*game)->name2) ||
            my_str_isequal((*game)->name1, (*game)->name2)) {
            my_putstr("Error: invalid name\n");
            ret_v = 1;
        }
    }
    free(entry);
    return ("-");
}

char *get_name1(data **game)
{
    char *entry = NULL;
    size_t buff = 0;

    for (int ret_v = 1; ret_v == 1;) {
        my_putstr("Enter Player 1's name: ");
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (free_alt(entry));
        free((*game)->name1);
        (*game)->name1 = my_cut_str(entry, 0, my_strlen(entry) - 2);
        if (my_str_isblank((*game)->name1)) {
            my_putstr("Error: invalid name\n");
            ret_v = 1;
        }
    }
    free(entry);
    return ("-");
}

char *get_names(data **game)
{
    if (get_name1(game) == NULL) {
        return ("n");
    }
    if (get_name2(game) == NULL)
        return ("n");
    return ("-");
}
