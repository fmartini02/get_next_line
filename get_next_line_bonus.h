/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:50:24 by fmartini          #+#    #+#             */
/*   Updated: 2025/03/10 19:03:30 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 666
# endif
# ifndef MAX_FD
#  define MAX_FD 4096
# endif
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_last_line
{
	char	*last_line;
	int		size;
}	t_last_line;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_strlen_char(const char *s, char c);
char	*ft_strdup(char *s);
char	*get_next_line_utils(char *line[4096], char *ret, char *tmp, int fd);
char	*ft_get_surplus(char *line);
char	*ft_update_line(char *line);
char	*ft_fill_line(int fd, char *ret);
char	*extract_line(char *line);

#endif
