/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:05:17 by kdune             #+#    #+#             */
/*   Updated: 2019/06/28 18:33:52 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (!alst || !*alst || !del)
		return ;
	while (*alst)
	{
		(void)del((*alst)->content, (*alst)->content_size);
		next = (*alst)->next;
		free((void *)(*alst));
		*alst = next;
	}
}
