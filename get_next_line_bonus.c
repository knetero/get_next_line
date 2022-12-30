/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:30:25 by abazerou          #+#    #+#             */
/*   Updated: 2022/12/30 20:12:08 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *read_line(char *save, int fd)
{
    char *buff;
    int i;
    
    i = 1;
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buff)
        return (NULL);
    while (i > 0 && !(ft_strchr(save, '\n')))
    {
        i = read(fd, buff, BUFFER_SIZE);
        if (i == 0)
            break ;
        if (i < 0)
		{
            free(buff);
            free(save);
            buff = NULL;
			return (NULL);
		}
        buff[i] = '\0';
        save = ft_strjoin(save, buff);
    }
    free(buff);
    buff = NULL;
    return (save);
}

char *first_line(char *save)
{
    char *res;
    int i;
    int j;

    i = 0;
    j = 0;
    while(save[i] && save[i] != '\n')
        i++;
    if (save[i] == '\n')
        i++;
    res = malloc(sizeof(char) * i + 1);
    if(!res)
        return (free(save), NULL);
    i = 0;
    while (save[j] && save[j] != '\n')
    {
        res[i++] = save[j++];
    }
    if (save[j] == '\n')
        res[i++] = '\n';
    res[i] = '\0';
    return (res);
}

char    *left_line(char *save)
{
    int i;
    char *res;
    int j;
    size_t len;

    i = 0;
    j = 0;
    while(save[i] && save[i] != '\n')
        i++;
    if (save[i] == '\n')
        i++;
    len = ft_strlen(save) - i;
    res = malloc(sizeof(char) * len + 1);
    if(!res)
        return (free(save), NULL);
    while(save[i])
    {
        res[j++] = save[i++];
    }
    res[j] = '\0';
    free(save);
    save = NULL;
    return (res);
}

char *get_next_line(fd)
{
    static char *save[10240];
    char *res;
    
    if(fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
        return (NULL);
    save[fd] = read_line(save[fd], fd);
    if (!save[fd])
		return (NULL);                  
    res = first_line(save[fd]);
    if (!res || res[0] == '\0')
		return (free(res), free(save[fd]), NULL);
    save[fd] = left_line(save[fd]);
    return(res); 
}

// int main()
// {
//     int fd;
//     int fd2;
//     int fd3;
//     int fd4;
//     int fd5;
//     int fd6;
//     int fd7;
//     int fd8;
//     int fd9;
//     int fd10;
//     int fd11;
//     int fd12;
//     int fd13;
//     int fd14;
//     int fd15;
//     int fd16;
    
//     fd = open("test.txt", O_RDONLY);
//     fd2 = open("test.txt", O_RDONLY);
//     fd3 = open("test.txt", O_RDONLY);
//     fd4 = open("test.txt", O_RDONLY);
//     fd5 = open("test.txt", O_RDONLY);
//     fd6 = open("test.txt", O_RDONLY);
//     fd7 = open("test.txt", O_RDONLY);
//     fd8 = open("test.txt", O_RDONLY);
//     fd9 = open("test.txt", O_RDONLY);
//     fd10 = open("test.txt", O_RDONLY);
//     fd11 = open("test.txt", O_RDONLY);
//     fd12 = open("test.txt", O_RDONLY);
//     fd13 = open("test.txt", O_RDONLY);
//     fd14 = open("test.txt", O_RDONLY);
//     fd15 = open("test.txt", O_RDONLY);
//     fd16 = open("test.txt", O_RDONLY);
    
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd2));
//     printf("%s", get_next_line(fd3));
//     printf("%s", get_next_line(fd4));
//     printf("%s", get_next_line(fd5));
//     printf("%s", get_next_line(fd6));
//     printf("%s", get_next_line(fd7));
//     printf("%s", get_next_line(fd8));
//     printf("%s", get_next_line(fd9));
//     printf("%s", get_next_line(fd10));
//     printf("%s", get_next_line(fd11));
//     printf("%s", get_next_line(fd12));
//     printf("%s", get_next_line(fd13));
//     printf("%s", get_next_line(fd14));
//     printf("%s", get_next_line(fd15));
//     printf("%s", get_next_line(fd16));
//     return (0);
// }