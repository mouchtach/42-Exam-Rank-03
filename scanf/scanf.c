#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

void    skip_spaces(void)
{
    char c = fgetc(stdin);
    while(c != EOF && isspace(c))
    {
        c = fgetc(stdin);
    }
    ungetc(c, stdin);
}

int scan_int(va_list var)
{

    int sign = 1;
    int result = 0;
    skip_spaces();
    char c = fgetc(stdin);

    if(c == EOF)
        return(0);
    if(c == '-' || c == '+')
    {
        if(c == '-')
            sign = -1;
    }
    char next_c = fgetc(stdin);
    if(isdigit(next_c))
        c = next_c;
    else 
    {
        ungetc(c, stdin);
        ungetc(next_c, stdin);
        return (0);
    }
    while(isdigit(c) && c != EOF)
    {
        result = (result * 10) + (c - '0');
        c = fgetc(stdin);
    }
    int *r = va_arg(var, int *);
    *r = result * sign;
    return(1);
}

int scan_string(va_list var)
{
    skip_spaces();
    char c = fgetc(stdin);
    if(c == EOF)
        return(0);
    char *str = va_arg(var , char *);
    int i = 0;
    while(!isspace(c) && c != EOF)
    {
        str[i++] = c;
        c = fgetc(stdin);
    }
    str[i] = 0;
    if(c != EOF)
        ungetc(c, stdin);
    if(i == 0)
        return(0);
    return (1);
}

int scan_char(va_list var)
{
    char c = fgetc(stdin);
    if(c == EOF)
        return(0);
    char *r = va_arg(var, char *);
    *r = c;
    return(1);
}

int ft_cases(char c, va_list var)
{
    if(c == 'd')
        return(scan_int(var));
    else if(c == 's')
        return(scan_string(var));
    else if(c == 'c')
        return(scan_char(var));
    else 
        return (0);
}

int ft_scanf(char *format, ...)
{
    int i = 0;
    int ret = 0;

    va_list var;
    va_start(var, format);

    while(format[i])
    {
        if(!isspace(format[i]))
        {
            if(format[i] == '%')
            {
                i++;
                if(ft_cases(format[i], var))
                    ret++;
            }
            else 
            {
                char c = fgetc(stdin);
                if(c == EOF || c != format[i])
                    break;
            }
        }
        i++;
    }
    return (ret);
}