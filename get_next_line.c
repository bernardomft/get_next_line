/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:29:32 by bmoran-f          #+#    #+#             */
/*   Updated: 2020/01/18 16:41:19 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_putstr(char *s)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        write(1,s+i,1);
        i++;
    }
}

static char *ft_insert_in_line(char *line)
{
    ft_putstr("inicio de insert in line\n");
    /*int     i;
    char    *temp;

    i = 0;
    while(aux[i] != 'n' && aux[i] != '0')
        i++;
    ft_putstr("Salto de linea o final encontrado\n");
    if(aux[i] == 'n')
    {
        line = ft_substr(aux,0,i);
        temp = ft_strdup(aux+(i + 1));
        aux = temp;
    } 
    else
    {
        line = ft_strdup(aux);
        free (aux);
        aux = NULL;
    }
    */
    return (line);
}


int get_next_line(int fd,char **line)
{
    static char     *aux[4096];
    int             ret;
    char            *buf;

     if (!(buf = (malloc(sizeof(char) * BUFFER_SIZE + 1))))
        return (-1);
    //ft_putstr("Memoria para buff reservada\n");
    
    while((ret = read(fd,buf,BUFFER_SIZE)) > 0)
    {
        printf("Se han leido %d bytes\n",ret);
        buf[ret] = '\0';
    //ft_putstr("contenido del buffer:\n*********************\n");
    //ft_putstr(buf); ft_putstr("\n*************************\n");
        if(aux[0] == NULL)
        {
            aux[0]= ft_strdup(buf);
            ft_putstr("Primera iteración\n");
        }
        else
        {
            ft_putstr("Cadenas unidas\n");
            aux[0] = ft_strjoin(aux[0],buf);  //Aquí esta el probelma.
        }
        if(ft_strchr(aux[0],'\n'))
            break;        
    }
     //ft_putstr("contenido del buffer:\n*********************\n");
     //ft_putstr(buf); ft_putstr("\n*************************\n");
    //ft_putstr("contenido de aux:\n************************ \n");
    //ft_putstr(aux[0]); ft_putstr("\n************************\n");
    //ft_putstr("contenido de aux:\n************************ \n");
    // ft_putstr(aux[0]); ft_putstr("\n************************\n");
    free(buf);
    //aux[0] = ft_insert_in_line(line[0]);
    if(ret == 0 )
        return (0);
    else if(ret > 0)
        return (1);
    else
        return(-1);
    //aux[0] = ft_insert_in_line(line,aux[fd],&ret);
}

