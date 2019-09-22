/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <kdune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 22:50:43 by kdune             #+#    #+#             */
/*   Updated: 2019/04/17 21:34:29 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	l;

	i = 0;
	while (src[i])
		i++;
	l = i;
	i = 0;
	while (i < n)
	{
		if (i >= l)
			while (i < n)
				dest[i++] = 0;
		else
			*(unsigned char *)(dest + i) = (unsigned char)src[i];
		i++;
	}
	return (dest);
}
