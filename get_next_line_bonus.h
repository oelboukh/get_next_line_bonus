/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:37:22 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/17 10:57:58 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*getln(char *sttc);
char	*readbuff(int fd, char *sttc);
char	*ft_strjoin(char const *s1, char const *s2);
char	*getafterlnx(char *sttc);
char	*ft_strdup(const char *s1);

#endif
