/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:51:05 by fmartini          #+#    #+#             */
/*   Updated: 2025/02/24 20:00:51 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	int		i;
	char	*c;

	i = 0;
	c = malloc(nmemb * size);
	while ((unsigned int)i < nmemb)
	{
		c[i] = 0;
		i++;
	}
	return (c);
}

int	ft_strlen_char(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	if (!s)
		return (NULL);
	len = ft_strlen_char(s, '\0');
	i = 0;
	while (i < len + 1)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	str = (char *)malloc(ft_strlen_char(s, '\0') + 1);
	if (!str)
		return (NULL);
	while (s[++i] != '\0')
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

/*this function join s1 and s2, freeing the s1*/
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	str = malloc((ft_strlen_char(s1, '\0') + ft_strlen_char(s2, '\0') + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (++i < ft_strlen_char(s1, '\0'))
		str[i] = s1[i];
	while (j < ft_strlen_char(s2, '\0'))
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	//free(s2);
	return (str);
}
