/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:05:02 by kdune             #+#    #+#             */
/*   Updated: 2019/04/11 22:05:48 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int c, size_t n)
{
	if (n)
		n--;
	else
		return (mem);
	while (n > 0)
	{
		*(unsigned char *)(mem + n) = c;
		n--;
	}
	*(unsigned char *)(mem + n) = c;
	return (mem);
}
