#include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

void ft_putstr2(char *s)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        write(1,s+i,1);
        i++;
    }
}

int main(void)
{
    int             ret = 1;
    int             fd_1, fd_2;
    char            *line[40096];
    int i = 0;
     static char     *aux[40096];

    //ft_putstr2("Empieza a leerse el archivo\n");
	fd_1 = open("poema1.txt", O_RDONLY);
    fd_2 = open("poema2.txt", O_RDONLY);
     
	if (fd_1 == -1 || fd_2 == -1)
	{
		ft_putstr2("Error\n");
		return (1);
	}
    
    printf("\n****************Comienza el test de dos pomeas****************\n");
    printf("\n++++++++++++++++POEMA 1: 47 LÍNEAS++++++++++++++++++++++++++++\n");
    
    while(ret > 0)
    {
        ret = get_next_line(fd_1,line);
        printf(" %d:    %s\n", i+1, line[0]);
        i++;
    }
    printf("\nLineas leídas: %d . Lienas esperadas: 47\n" ,i);

    printf("\n++++++++++++++++POEMA 2: 57 LÍNEAS++++++++++++++++++++++++++++\n");
    ret = 1;
    i = 0;
    while(ret > 0)
    {
        ret = get_next_line(fd_2,line);
        printf(" %d:    %s\n", i+1, line[0]);
        i++;
    }
    printf("\nLineas leídas: %d. Lienas esperadas: 57\n", i);
}