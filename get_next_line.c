/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 01:13:45 by yobourai          #+#    #+#             */
/*   Updated: 2024/03/30 20:53:16 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdlib.h>
#include "get_next_line.h"
char *ft_strdup(char *ptr)
{
    char *str ;
    int i = 0;
    str =malloc(ft_strlen(ptr) + 1);
    while(ptr[i] && ptr)
    {
        str[i] =ptr[i];
        i++;
    }
        str[i]='\0';
    return str ;
}
char *ft_saveline(char *str)
{
	char	*new;
    int 	i;
    i = 0;

	int size = ft_strchr(str);
    if (size == 0)
        return NULL;
    new = &str[size];
	while(new && new[i])
         i++;
	if (!i)
        ft_free(&str);
    char* ptr = (char *)malloc(i + 1);
	if (!ptr)
		return (NULL);
    i=0;
    while(new && new[i])
    {
        ptr[i] = new[i];
        i++;
    }
    ptr[i] = '\0';
    free(str);
    return ptr ;
}
char *ft_newline(char *ptr)
{
    int i;
    char *str ;
    
	i = 0;
	int size =ft_strchr(ptr);
    str =malloc(size);
    if(!str )
        return NULL ;
    while(ptr && (ptr[i] && ptr[i] != '\n'))
    {
        str[i]=ptr[i];
        i++;
    }
    if(ft_strchr(ptr))
    {
                str[i]='\n';
	        str[i+1]='\0';
    }
    else 
        str[i] = '\0';
    
	return str;
}
char *get_next_line(int fd)
{
    static char *ptr; 
    ssize_t     nbyte;
    char        *str;
    
    nbyte = BUFFER_SIZE;
    str = (char *)malloc(BUFFER_SIZE + 1);
 if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(ptr);
        free(str);
        ptr = NULL;
        str = NULL;
        return (NULL);
    }
    if(!str)
        ft_free(&ptr);
    while(nbyte>0)
    {
        nbyte = read(fd, str, BUFFER_SIZE);
        str[nbyte] = '\0';
        ptr = ft_strjoin(ptr, str);
        if (ft_strlen(ptr) == 0)
            ft_free(&ptr);
        if (!ptr)
        {
            free(str);
            str= NULL ;
            return (NULL);
        }
        if (ft_strchr(ptr) && nbyte != 0)
            break;
    }
    ft_free(&str);
    str = ft_newline(ptr);
    ptr = ft_saveline(ptr);
    return (str);
}
 int main()
{
    char *str;
    int fd;
    fd = open("txt.txt", O_RDONLY); 
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}