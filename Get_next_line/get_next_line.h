/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:48:59 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/15 21:53:40 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buff);
int		ft_strlen_n(char *s, int c);
char	*ft_strdup_gnl(char *s1);
int		ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_firstl(char *buff);
char	*ft_nextl(char *buff);

#endif