#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int  ft_strchr(char *str )
{
    int i ;
    i = 0;       

    while(str && str[i])
    {
        if(str[i] == '\n')
          return (i + 1);
        i++;
    }
    // if(nbyte <= BUFFER_SIZE)
    //     return i;
    return 0;
}
char *ft_saveline(char *str)
{
	char	*new;
    int 	i;
    i = 0;

	int size = ft_strchr(str) + 1;

    	new =str+ size;
	while(new && new[i])
         i++;
	if (!i)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
    char* ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
    i=0;
    while(new && new[i])
    {
        ptr[i] = new[i];
        i++;
    }
    ptr[i] = '\0';
        // free(str);
	    // str = NULL;
    return ptr ;
}
int main()
{
    char *str =ft_saveline("youness\nggfffdklmkdn");
    printf("%s",str);
}