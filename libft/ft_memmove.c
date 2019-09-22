/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:49:16 by kdune             #+#    #+#             */
/*   Updated: 2019/04/11 22:02:12 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*memmove_end(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i > 0)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i--;
	}
	*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	return (dest);
}

static void	*memmove_begin(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0)
		return (dest);
	if (src < dest)
		return (memmove_end(dest, src, n));
	else if (src > dest)
		return (memmove_begin(dest, src, n));
	else
		return (dest);
}
