/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:13:45 by yobourai          #+#    #+#             */
/*   Updated: 2024/03/20 05:56:08 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdlib.h>
#include "get_next_line.h"


char *ft_newline(char *ptr, int* n)
{
    int i =0;
    char *str ;
    str = malloc(ft_strchr(ptr) +2);
    if(!str)
        return NULL ;
    while(ptr && (ptr[i] && ptr[i] != '\n'))
    {
        str[i] = ptr[i];
        i++;
    }
    str[i] = '\n';
    *n = i + 1;
    str[i+1]='\0';
    return str ;
}
char *get_next_line(int fd)
{
    char *str;
    static char *ptr; 
    int n = 0;
    
    ssize_t nbyte = 1;
    str = malloc(BUFFER_SIZE + 1);
    if(!str)
        return NULL;
    while(nbyte >0)
    {
        nbyte = read(fd , str , BUFFER_SIZE);
        ptr = ft_strjoin(ptr,str);
        if (ft_strchr(ptr))
            break ;
    }
    free(str);
    str = ft_newline(ptr, &n);
    if (nbyte == 0)
    {
        free(str);
        return NULL;
    }
    ptr = ft_saveline(&ptr, n);
    return (str);
}
// int main()
// {
//     char *str;
//     int fd;
//     fd = open("txt.txt", O_RDONLY); 
//     while(1)
//     {
//         str = get_next_line(fd);
//         printf("%s", str);
//         printf("********\n");
//         if (str == NULL)
//             break;
//         free(str);
//     }
// }