/*
** EPITECH PROJECT, 2018
** CPool_Day09_2018
** File description:
** my library headers
*/

#ifndef MY_H_
#define MY_H_

typedef enum {
    SUCCESS = 0,
    FAILURE = 84,
    TRUE = 1,
    FALSE = 0,
    YES = 1,
    NO = 0,
    ERROR = -1,
    END_OF_FILE = -1,
    END_OF_ARGS = -1,
    CTRLD = -1,
} return_values_t;

typedef	unsigned int uint;
typedef	unsigned char uchar;

unsigned short my_putchar(char const c);
unsigned short my_putchar_err(char const c);
unsigned short my_putstr(char const *str);
unsigned short my_puterr(char const *str);
unsigned short my_putarr(char * const *arr, char c);
void free2(char *s1, char *s2);
void free3(char *s1, char *s2, char *s3);
unsigned int my_atou(char const *str);
int my_getnbr(char const *str);
unsigned short my_putnbr_err(int);
unsigned short my_putnbr(int nb);
void my_charcat(char *str, char const c);
char *my_strdup(char const *src);
char **my_arrdup(char **arr, int size);
int my_swap(int *a, int *b);
char *my_evil_str(char *str);
unsigned int my_strlen(char const *str);
unsigned int my_compute_power_rec(int nb, int p);
char *my_nstrcpy(char *dest, char const *src, unsigned int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, unsigned int n);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, unsigned int n);
char *my_strcat(char *dest, char const *src);
char *my_nstrcat(char *dest, char const *src, unsigned int n);
int my_strncmp(char const *s1, char const *s2, unsigned int n);
unsigned short my_c_isalpha(char const c);
unsigned short my_c_isblank(char c);
unsigned short my_c_isnum(char const c);
unsigned short my_c_islower(char const c);
unsigned short my_c_isupper(char const c);
unsigned short my_isneg(int nb);
int my_isnum(char const *str);
unsigned short my_str_isalpha(char const *str);
unsigned short my_str_isblank(char const *str);
unsigned short my_str_isnum(char const *str);
unsigned short my_str_islower(char const *str);
unsigned short my_str_isupper(char const *str);
unsigned short my_str_isneg(char const *str);
unsigned short my_c_isprintable(char c);
unsigned short my_str_isprintable(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strcmpu(char const *s1, char const *s2);
int my_strcmpi(char const *s1, char const *s2);
char *erase_str(char *dest, char const *str);
char *my_strstr(char *str, char const *to_find);
char **my_cut_word_array(char **, int const, int const);
char *my_cut_str(char const *, int const, int const);
char *my_cut_word_n_from_str(char const *s, int n);
int my_int_isinarray(int *array, int const nb, int size);
int my_str_isinarray(char **array, char const *s);
int my_str_startswith(char const *s1, char const *s2);
int my_str_endswith(char const *s1, char const *s2);
int my_c_isinstr(char const *str, char const c);
void free_array(char **array);
int my_str_isequal(char const *s1, char const *s2);
int my_str_isequal_insensitive(char const *s1, char const *s2);
int my_str_isinarray_insensitive(char const **array, char const *s);
int my_word_array_isequal(char const **arr1, char const **arr2);
int my_word_array_isequal_insensitive(char const **arr1, char const **arr2);

int my_qurt(unsigned int const nb);
int my_cbrt(unsigned int const nb);
int my_sqrt(unsigned int const nb);

char *my_utoa(unsigned int nb);
char *my_itoa(int nb);
int ctoi(char const c);
char itoc(int const i);
char *ctos(char const c);
char stoc(char const *s);

unsigned short isletter(char const c);
unsigned int count_str(char const *str);
char **my_str_to_word_array(char const *str);

#endif
