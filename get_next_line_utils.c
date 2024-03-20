/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:34:21 by yobourai          #+#    #+#             */
/*   Updated: 2024/03/20 05:52:20 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int ft_strlen(char *str)
{
    int i = 0;
    
    while(str && str[i])
        i++;
    return i ;
}
char *ft_strjoin(char *str , char *ptr)
{
    int i = 0 ;
    int j = 0;
    char *tmp ;
    tmp = malloc(ft_strlen(str)+ ft_strlen(ptr)+ 1);
        if(!tmp)
           return (NULL) ;
    while(str && str[i])
    {
            tmp[i]= str[i];
            i++;            
    }
   if(!str)
        free(str);
    while( ptr &&ptr[j])
    {
        tmp[i] = ptr[j];
        i++;
        j++;
    }
     if(!ptr)
        free(ptr);
    tmp[ft_strlen(str)+ ft_strlen(ptr)] = '\0';
    
    return tmp ;
}
int  ft_strchr(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == '\n')
          return (i+1);
        i++;
    }
    return 0;
}
char *ft_saveline(char **str, int n)
{
    char    *new;
    int     j;
    
    j = 0;
    new = *str;
    while( new && new[j] !='\n')
         j++;
    char* ptr = malloc(j +1);
    j = 0;
    while(new[n + j])
    {
        ptr[j] = new[n + j];
        j++;
    }
    ptr[j] = '\0';
    free(new);
    new = NULL;
    return ptr ;
}
