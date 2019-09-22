/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <kdune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:45:59 by kdune             #+#    #+#             */
/*   Updated: 2019/04/17 22:41:04 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *need)
{
	size_t	i1;
	size_t	i2;
	size_t	j;

	i1 = 0;
	if (need[0] == 0)
		return ((char *)hay);
	while (hay[i1])
	{
		if ((unsigned char)hay[i1] == (unsigned char)need[0])
		{
			j = 0;
			i2 = i1;
			while ((unsigned char)hay[i2] == (unsigned char)need[j] && need[j])
			{
				i2++;
				j++;
			}
			if (j == ft_strlen(need))
				return ((char *)hay + i2 - j);
		}
		i1++;
	}
	return (NULL);
}
