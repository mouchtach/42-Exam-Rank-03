#include  <stdio.h>
#include  <unistd.h>
#include  <fcntl.h>
#include  <stdlib.h>


void    f_clean(char *str1, char *str2)
{
    if(str1)
        free(str1);
    if(str2)
        free(str2);
}

char *search_and_replace(char *str, char *find)
{
    int i = 0;
    int x = 0;
    int j;

    while(str[i])
    {
        if(str[i] == find[x]) 
        {
            j = i;
            while(find[x] && str[j] == find[x])
            {
                x++;
                j++;
            }
            if(find[x] == 0)
            {
                while(str[i] && x--)
                    str[i++] = '*';
                i--;
            }     
            x = 0;
        }
        i++;
    }
    return(str);
}

char *ft_reader(void)
{
    char *buffer = malloc(11);
    char *join = NULL;
    int r;
    int i = 0;
    int j = 0;

    if (!buffer)
        return (printf("malloc faild\n"), f_clean(buffer, join), NULL);
    while (1)
    {
        r = read(STDIN_FILENO, buffer, 10);
        if (r < 0)
            return (printf("read faild\n"), f_clean(buffer, join), NULL);
        if (r == 0)
            break;
        join = realloc(join, i + r + 1);
        if(!join)
            return (printf("realloc faild\n"), f_clean(buffer, join), NULL);
        while(j < r)
            join[i++] = buffer[j++];
        j = 0;
        join[i] = '\0';
    }
    if (buffer)
        free(buffer);
    return (join);
}

int main(int ac, char **av)
{
    if(ac != 2)
        return(printf("error in argument\n"), 1);
    char *str;
    str = ft_reader();
    if(!str)
        return(1);
    printf("%s", search_and_replace(str, av[1]));
    return (0);
}