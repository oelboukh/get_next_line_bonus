/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:57:38 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/17 10:45:21 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*readbuff(int fd, char *sttc)
{
	int		i;
	char	*s;
	char	*tmp;

	s = malloc((size_t)BUFFER_SIZE + 1);
	i = read(fd, s, BUFFER_SIZE);
	if (i < 0)
	{
		free(sttc);
		free(s);
		return (NULL);
	}
	while (i > 0)
	{
		s[i] = '\0';
		tmp = ft_strjoin(sttc, s);
		free(sttc);
		sttc = tmp;
		if (ft_strchr(sttc, '\n'))
			break ;
		i = read(fd, s, BUFFER_SIZE);
	}
	free(s);
	return (sttc);
}

char	*getafterlnx(char *sttc)
{
	int		i;
	char	*ptr;

	i = 0;
	while (sttc[i] != '\n' && sttc[i] != '\0')
		i++;
	if (sttc[i] == '\0')
	{
		free(sttc);
		return (NULL);
	}
	i++;
	ptr = ft_strdup(sttc + i);
	free (sttc);
	return (ptr);
}

char	*getln(char *sttc)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (sttc[i] == '\0')
		return (NULL);
	while (sttc[i] != '\n' && sttc[i])
		i++;
	new = malloc(i + 2);
	while (j <= i)
	{
		new[j] = sttc[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*sttc[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sttc[fd] = readbuff(fd, sttc[fd]);
	if (!sttc[fd])
		return (NULL);
	line = getln(sttc[fd]);
	sttc[fd] = getafterlnx(sttc[fd]);
	return (line);
}
