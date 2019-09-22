/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:00:11 by kdune             #+#    #+#             */
/*   Updated: 2019/06/28 18:19:32 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (n)
		n--;
	else
		return (dest);
	if (dest == src)
		return (dest);
	while (n > 0)
	{
		*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		n--;
	}
	*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	return (dest);
}
