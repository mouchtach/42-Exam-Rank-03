#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char *get_var(char *str, int *rm_close, int *rm_open, int *len)
// had fuction drt buha copy dyal av[1] and check is valid caracter "(" ")" o calcul chhal dyal open o close li khasni ndelete
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == '(')
        {
            if(*rm_close == 0)
                (*rm_open)++;
            else 
                (*rm_close)--;
        }
        else if (str[i] == ')')
        {
            if(*rm_open == 0)
                (*rm_close)++;
            else
                (*rm_open)--;
        }
        else 
            return(NULL);
        i++;
    }
    *len = i;
    char *new = malloc(i + 1);
    i = 0;
    while (str[i])
    {
       new[i] = str[i];
       i++;
    }
    new[i] = 0;
    return (new);
}


void    rip(char *str, char *result, int i , int rm_open, int rm_close, int open)
{
    // print
    if(str[i] == '\0') // hna kan printe result fach hatwsal lhad case
    {
        if(rm_close == 0 && rm_open == 0 && open == 0)
        {
            result[i] = 0;
            printf("%s\n", result);
            return ; 
        }
    }
    // remove
    if(str[i] == '(' && rm_open > 0)
    {
        result[i] = ' ';
        rip(str, result, i + 1, rm_open - 1, rm_close, open);
    }
    if(str[i] == ')' && rm_close > 0)
    {
        result[i] = ' ';
        rip(str, result, i + 1, rm_open , rm_close - 1, open);
    }
    // keep
    if(str[i] == '(')
    {
        result[i] = str[i];
        rip(str, result, i + 1, rm_open , rm_close , open + 1);
    }
    if(str[i] == ')' && open > 0)
    {
        result[i] = str[i];
        rip(str, result, i + 1, rm_open , rm_close , open - 1);
    }
}

int main(int ac, char **av)
{
    if(ac != 2)
        return(0);
    int rm_open = 0;
    int rm_close = 0;
    int len = 0;
    char *str = get_var(av[1], &rm_close, &rm_open, &len);
    char *result = malloc(len +1 );
    if(!str)
        return(1);
    rip(str, result, 0, rm_open, rm_close, 0);
    free(str);
    free(result);
}