/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:39:25 by kdune             #+#    #+#             */
/*   Updated: 2019/06/28 21:09:52 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_strlen(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (len);
}

static int		st_wordcounter(char const *s, char c)
{
	int	i;
	int	wordc;

	i = 0;
	wordc = 0;
	if (s[0] == 0)
		return (wordc);
	if (s[i] != c)
		wordc++;
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			wordc++;
		i++;
	}
	return (wordc);
}

static char		**st_free(char ***tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&(*tab[i]));
		i++;
	}
	free(*tab);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	t;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	t = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (st_wordcounter(s, c) + 1))))
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i] && s[0])
	{
		len = st_strlen(&s[i], c);
		if (!(tab[t++] = ft_strnew(len)))
			return (st_free(&tab));
		tab[t - 1] = ft_strncpy(tab[t - 1], &s[i], len);
		i += len;
		while (s[i] == c)
			i++;
	}
	tab[t] = 0;
	return (tab);
}
