#include "rush.h"

char *append_zeros(char *str, int number_of_zeros)
{
    int i;

    i = 0;
    while(i < number_of_zeros)
    {
        str[1 + i] = '0';
        i ++;
    }
    str[i] = '\0';
    return str;
}

void    logic(struct s_arguments *args)
{
    int i;
    int length;
    char *printable;
    char * number = args->number;
    length = ft_strlen(number);
    i = 0;
    write(1, "this code ran", 13);
    while(number[i] != '\0')
    {
        printable = append_zeros(number, length - i -1);
        write(1, &printable, length - i);
        i ++;
    }
    
}