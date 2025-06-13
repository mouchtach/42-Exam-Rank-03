#include "get_next_line.h"

char *ft_strdup(char *str)
{
    if (!str)
        return(NULL);
    int len = 0;
    while(str[len])
        len++;
    char *new = malloc(len + 1);
    len = 0;
    while (str[len])
    {
        new[len] = str[len];
        len++;
    }
    new[len] = 0;
    return(new);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int b_pos;
    static int b_read;

    char line[70000];
    int i = 0;

    if(fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    while(1)
    {
        if(b_pos == b_read)
        {
            b_read = read(fd, buffer, BUFFER_SIZE);
            b_pos = 0;
            if(b_read <= 0)
                break;
        }
        line[i++] = buffer[b_pos++]; //hna ghdi nhot character fl line 
        if(buffer[b_pos - 1] == '\n') //hna ghadi ntcheck wach caracter li daz new line "\n";
            break;
    }
    line[i] = 0;
    if(i == 0)
        return (NULL);
    return(ft_strdup(line));
}

// int main()
// {
//     int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
//     if(fd < 0)
//         return(1);
//     int i = 1;

//     printf("line %d = %s", i++, get_next_line(fd));
//     printf("line %d = %s", i++, get_next_line(fd));
//     printf("line %d = %s", i++, get_next_line(fd));
//     printf("line %d = %s", i++, get_next_line(fd));

// }