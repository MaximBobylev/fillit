/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 06:21:47 by marvin            #+#    #+#             */
/*   Updated: 2019/04/11 22:07:44 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char	*begin;

	begin = dst;
	while (*dst != 0)
		dst++;
	while (*src != 0)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = *src;
	return (begin);
}
