/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <kdune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:18:37 by kdune             #+#    #+#             */
/*   Updated: 2019/04/17 22:50:52 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_strlen(const char *str)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (SPACE1(str[i]))
		i++;
	while (str[i])
	{
		len++;
		i++;
	}
	if (i)
		i--;
	while (SPACE1(str[i]) && len > 0)
	{
		i--;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;
	size_t	len;

	if (!s)
		return (NULL);
	len = st_strlen(s);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (SPACE1(s[i]))
		i++;
	(void)ft_strncpy(ret, (char const *)&s[i], len);
	return (ret);
}
