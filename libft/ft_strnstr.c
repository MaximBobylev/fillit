/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <kdune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:37:00 by kdune             #+#    #+#             */
/*   Updated: 2019/04/17 23:02:07 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*st_ifwhile(size_t i, size_t len, const char *hay, const char *need)
{
	size_t	j;

	j = 0;
	while (hay[i] == need[j] && need[j] && len > 0)
	{
		i++;
		j++;
		len--;
	}
	if (j == ft_strlen(need))
		return ((char *)hay + i - j);
	else
		return (0);
}

char		*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i1;
	char	*res;

	i1 = 0;
	if (need[0] == 0)
		return ((char *)hay);
	while (hay[i1] && len > 0)
	{
		if (hay[i1] == need[0])
			if ((res = st_ifwhile(i1, len, hay, need)) != 0)
				return (res);
		i1++;
		len--;
	}
	return (NULL);
}
