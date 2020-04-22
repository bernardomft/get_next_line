/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoran-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:29:47 by bmoran-f          #+#    #+#             */
/*   Updated: 2020/01/18 16:41:27 by bmoran-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup( char *s1)
{
	int		leng;
	char	*res;
	int		i;

	leng = ft_strlen(s1);
	res = malloc(sizeof(char) * (leng + 1));
	i = 0;
	if (!res)
		return (NULL);
	while (i < leng)
	{
		res[i] = s1[i];
		i++;
	}
	res[leng] = '\0';
	return (res);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	char	*result;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)))) // Añadido + 1 para que no pete
		return (NULL);
	j = 0;
	printf("Longuitud de la cadena 1: %ld\n", ft_strlen(s1));
	printf("Longuitud de la cadena : %ld\n", ft_strlen(s2));
	
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	//printf("Cadena 1 añadida\n");
	
	//i = ft_strlen(s1);
	//result = ft_strdup(s1);
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (result);
	
}

char	*ft_substr(char  *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		count;
	size_t		start2;

	start2 = start;
	count = 0;
	if (s == NULL)
		return (0);
	if (start > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (!(ptr = malloc((sizeof(char) * (len) + 1))))
		return (0);
	while (start < (len + start2))
		ptr[count++] = s[start++];
	ptr[count] = '\0';
	return (ptr);
}

size_t		ft_strlen( char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr( char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	if (!c && *s == '\0')
		return ((char *)s);
	return (NULL);
}

