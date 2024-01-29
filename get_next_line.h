/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:51:50 by fmartini          #+#    #+#             */
/*   Updated: 2022/11/25 17:51:56 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 666
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_buf(int fd, char *mem);
int		ft_strlen(const char *s);
char	*ft_set_mem(char *mem);
char	*ft_line_builder(char *buf);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
char	*ft_set_new_mem(char *mem, int i);

#endif
