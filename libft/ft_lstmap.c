/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:28:10 by kdune             #+#    #+#             */
/*   Updated: 2019/06/28 21:02:08 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		st_lpb(t_list **newlst, t_list *(*f)(t_list *elem), t_list *elm)
{
	if (*newlst == NULL)
	{
		if (!(*newlst = f(elm)))
			return (1);
		(*newlst)->next = NULL;
	}
	else
	{
		if (!((*newlst)->next = f(elm)))
			return (1);
		(*newlst)->next->next = NULL;
	}
	return (0);
}

static t_list	*st_free(t_list *beginlst)
{
	t_list	*tmp;

	if (!(beginlst))
		return (NULL);
	while (beginlst)
	{
		tmp = beginlst;
		beginlst = beginlst->next;
		free(tmp);
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*beginlst;

	if (!lst || !f || !*f)
		return (NULL);
	newlst = NULL;
	beginlst = NULL;
	while (lst)
	{
		if (st_lpb(&newlst, f, lst))
			return (st_free(beginlst));
		if (newlst->next)
			newlst = newlst->next;
		else
			beginlst = newlst;
		lst = lst->next;
	}
	return (beginlst);
}
