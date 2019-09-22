/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <kdune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:58:26 by kdune             #+#    #+#             */
/*   Updated: 2019/04/17 21:19:36 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1l;

	if (!s1 || !s2)
		return (NULL);
	s1l = ft_strlen(s1);
	if (!(ret = ft_strnew(s1l + ft_strlen(s2))))
		return (NULL);
	(void)ft_strcpy(ret, s1);
	(void)ft_strcpy((ret + s1l), s2);
	return (ret);
}
