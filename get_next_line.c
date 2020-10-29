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

 char  *ft_insert_in_line(char *aux, char **line, int *ret)
{
   
    int     i;
    char    *temp;

    i = 0;
    while(aux[i] != '\n' && aux[i] != '\0')
        i++;
    if(aux[i] == '\n')
    {
        *line = ft_substr(aux,0,i);
        temp = ft_strdup(aux+(i+1));
        free(aux);
        aux = temp;
        if (aux[0] == '\0')
        {
            free(aux);
            aux = NULL;
        }
		*ret = 1;
    } 
    else
    {
        *line = ft_strdup(aux);
        free (aux);
        aux = NULL;
        *ret = 0;
    }
    return(aux);
}



int get_next_line(int fd,char **line)
{
    static char     *aux[40096];
    int             ret;
    char            *buf;

    if (!line || fd == -1 || BUFFER_SIZE < 1)
		return (-1);
    if (!(buf = (malloc(sizeof(char) * BUFFER_SIZE + 1))))
        return (-1);
    while((ret = read(fd,buf,BUFFER_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if(aux[fd] == NULL)
        {
            aux[fd]= ft_strdup(buf);
        }
        else
        {
            aux[fd] = ft_strjoin(aux[fd],buf);  
        }
        if(ft_strchr(aux[fd],'\n'))
            break;        
    }
    free(buf);
    if((ret < 0) || (ret == 0 && aux[fd] == NULL))
    {
        if(ret < 0)
            return -1;
        *line = ft_strdup("");
        return 0;
    }
    aux[fd]=ft_insert_in_line(aux[fd], line, &ret);
    return(ret);
}

