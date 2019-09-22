/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:07:08 by kdune             #+#    #+#             */
/*   Updated: 2019/06/28 21:27:03 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		l;

	if (!str || !*str)
		return (NULL);
	l = ft_strlen((const char *)str) - 1;
	i = 0;
	while (i < l)
	{
		tmp = str[i];
		str[i++] = str[l];
		str[l--] = tmp;
	}
	return (str);
}
