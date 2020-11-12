/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:41:07 by bmoran-f          #+#    #+#             */
/*   Updated: 2020/01/18 16:41:11 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 32
#endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

int         get_next_line(int fd,char **line);
char	    *ft_strdup( char *s1);
char	    *ft_strjoin(char  *s1, char  *s2);
char	    *ft_substr(char  *s, unsigned int start, size_t len);
size_t		ft_strlen( char *str);
char	    *ft_strchr( char *s, int c);
size_t	    ft_stchr_pos(char *s, char c);
void	    *ft_memset(void *str, int c, size_t n);

#endif

