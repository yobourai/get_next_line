#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int ft_strlen(char *str)
{
    int i = 0;
    
	if(!str)
		return (0);
    while(str && str[i])
        i++;
    return i ;
}
char *ft_strjoin(char *ptr, char *str)
{
    int i = 0;
    int j = 0;
	int 	size;
	char	*new;
    if(!ptr)
        return strdup(str);
	size = ft_strlen(str) + ft_strlen(ptr);
    new = malloc(size + 1);
    if(!new)
        return (NULL);
    while(ptr && ptr[i])
    {
        new[i] = ptr[i];
        i++;            
    }

    while(str && str[j])
        new[i++] = str[j++];
    new[size] = '\0';
    return new;
}
int main()
{
    char *str = ft_strjoin(NULL , "brs");
    printf("%s",str);
}