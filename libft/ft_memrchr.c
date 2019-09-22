/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:47:39 by kdune             #+#    #+#             */
/*   Updated: 2019/06/26 21:15:11 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *mem, int c, size_t n)
{
	if (n)
		n--;
	else
		return ((void *)mem);
	while (n > 0)
	{
		if (*(unsigned char *)(mem + n) == (unsigned char)c)
			break ;
		n--;
	}
	if (n == 0 && *(unsigned char *)(mem + n) != (unsigned char)c)
		return (NULL);
	else
		return ((void *)(mem + n));
}
