/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:55:36 by kdune             #+#    #+#             */
/*   Updated: 2019/06/26 18:22:55 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *dest, const char *src, int c)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		*(unsigned char *)(dest + i) = (unsigned char)src[i];
		if (*(unsigned char *)(src + i) == (unsigned char)c)
			break ;
		i++;
	}
	if (i == ft_strlen(src))
		return (NULL);
	dest[i] = 0;
	return (dest);
}
