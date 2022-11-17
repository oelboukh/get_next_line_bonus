/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelboukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:17:05 by oelboukh          #+#    #+#             */
/*   Updated: 2022/11/16 14:18:33 by oelboukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (((char *)s) + i);
		i++;
	}
	if (s[i] == (char)c)
		return (((char *)s) + i);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	count(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	len_cpy(const char *s1, char *new, int x)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		new[x] = s1[i];
		i++;
		x++;
	}
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	char	*new;
	int		aloc;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	x = 0;
	i = count(s1);
	x = count(s2);
	aloc = (i + x);
	new = malloc(sizeof(char) * (aloc) + 1);
	if (!new)
		return (NULL);
	i = 0;
	i = len_cpy (s1, new, i);
	i = len_cpy (s2, new, i);
	new[i] = 0;
	return (new);
}
