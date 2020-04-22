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
    static char     *aux[4096];
    int             ret;
    int             fd;
    char            **line;
    int i = 0;

    ft_putstr2("Empieza a leerse el archivo\n");
	fd = open("quijote.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr2("Error\n");
		return (1);
	}
    else
        ft_putstr2("Archivo leido correctamente\n");
    
    
    ft_putstr2("Empieza la llamada a get_next_line\n");
    while(i < 2)
    {
        ret = get_next_line(fd,line);
        printf("Retorno de la funcion: %d\n", ret);
        i++;
    }
    
}