/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <kdune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 01:08:33 by kdune             #+#    #+#             */
/*   Updated: 2019/04/17 20:47:48 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *str, size_t size)
{
	size_t	len;

	len = 0;
	while (str[len] && size > 0)
	{
		len++;
		size--;
	}
	return (len);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstl;
	size_t	srcl;

	dstl = ft_strnlen(dst, size);
	srcl = ft_strlen(src);
	if (size == 0)
		return (dstl + srcl);
	dst += dstl;
	if (dstl == size)
		return (dstl + srcl);
	if (size > dstl + srcl)
		(void)ft_memcpy(dst, src, srcl + 1);
	else
	{
		(void)ft_memcpy(dst, src, size - dstl - 1);
		dst[size - dstl - 1] = 0;
	}
	return (dstl + srcl);
}
