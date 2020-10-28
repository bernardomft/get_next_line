#include "get_next_line.h"

int main(void)
{
    int ret = 1;
    char **line;
    printf("\nEmpieza la prueba\n");
    printf("\nSe va a brir el aerchivo poemas.txt\n");

    int fd;
    int i = 0;
    fd = open("poemas.txt", O_RDONLY);
    if(fd == -1)
        printf("\nError al leer el archivo\n");
    else
    {
        printf("\nArchivo leido correctamente\n");
        while (ret == 1)
        {
            ret = get_next_line(fd,line);
            printf("Line: ---%s---\n ", line[0]);
        }
    }
    

}