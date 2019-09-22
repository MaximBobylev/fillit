/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <kdune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:31:08 by kdune             #+#    #+#             */
/*   Updated: 2019/04/17 23:00:35 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	l;
	char	*str;

	l = 0;
	while (src[l])
		l++;
	if (!(str = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	l = 0;
	while (src[l])
	{
		*(unsigned char *)(str + l) = *(unsigned char *)(src + l);
		l++;
	}
	*(unsigned char *)(str + l) = (unsigned char)'\0';
	return (str);
}
