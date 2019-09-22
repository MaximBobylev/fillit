/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <kdune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:46:31 by kdune             #+#    #+#             */
/*   Updated: 2019/04/17 21:37:14 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	if (size + 1 == 0)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size > 0)
	{
		ret[size] = 0;
		size--;
	}
	ret[size] = 0;
	return (ret);
}
