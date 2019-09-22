/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:33:32 by kdune             #+#    #+#             */
/*   Updated: 2019/06/28 16:42:33 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *first, void *second)
{
	size_t	tmp;

	if (first || second)
		return ;
	tmp = *(size_t *)(first);
	*(size_t *)(first) = *(size_t *)(second);
	*(size_t *)(second) = tmp;
}
