/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:31 by rafasant          #+#    #+#             */
/*   Updated: 2024/06/16 22:39:01 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_str(int fd, char *buffer, char *str);
void	adjust_buffer(char *buffer, int len);
size_t	ft_strlen_c(char *str, char c);
char	*ft_strndup(char *str, int len);
char	*ft_strjoin_n(char *s1, char *s2, int len);

#endif