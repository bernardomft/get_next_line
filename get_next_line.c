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

static int     ft_return_values(int ret, char **line)
{
    if(ret < 0)
        return (-1);
    *line = ft_strdup(""); 
    return (0);
}

static char     *ft_insert_in_line(char **line, char *aux,int *ret)
{
    int     count;
    char    *temp;

    count = 0;
    while(aux[count] != '\n' && aux[count] != '\0')
        count++;
    if(aux[count] == '\n')
    {
        *line = ft_substr(aux, 0, count);
        *ret = 1;
        temp = ft_strdup(aux + (count + 1));
        aux = temp;
    }
    else
    {
        *line = ft_strdup(aux);
        *ret = 0;
        free (aux);
        aux = NULL;
    }
    return (aux);
}

int         get_next_line(int fd, char **line)
{
    static char     *aux[4096];
    char            *buf;
    int             ret;

    if (!(buf = (malloc(sizeof(char) * BUFFER_SIZE + 1))))
        return (-1);
    while((ret = read(fd, buf,BUFFER_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (aux[fd] == NULL)
            aux[fd] = ft_strdup(buf);
        else 
            aux[fd] = ft_strjoin(aux[fd],buf);
        if (ft_strchr(aux[fd], '\n'))
            break;
    }
    free(buf);
    if (ret < 0 || (aux[fd] == NULL & ret == 0))
        return (ft_return_values(ret, line));
    aux[fd] = ft_insert_in_line(line,aux[fd],&ret);
    return (ret);
}

