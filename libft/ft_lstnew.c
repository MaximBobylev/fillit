/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:07:35 by kdune             #+#    #+#             */
/*   Updated: 2019/04/16 20:16:36 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newelem;

	if (!(newelem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newelem->next = (NULL);
	if (content == NULL)
	{
		newelem->content = NULL;
		newelem->content_size = 0;
		return (newelem);
	}
	if (!(newelem->content =
	(void *)malloc(sizeof(newelem->content) * content_size)))
		return (NULL);
	(void)ft_memcpy((void *)newelem->content, content, content_size);
	newelem->content_size = content_size;
	newelem->next = NULL;
	return (newelem);
}
