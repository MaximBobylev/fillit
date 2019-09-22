/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:26:36 by kdune             #+#    #+#             */
/*   Updated: 2019/09/21 20:22:06 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i][0])
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
}

int		coordadd(char x, char y, t_coord **alst)
{
	t_coord	*newelm;
	t_coord	*cur;

	cur = *alst;
	if (!(newelm = (t_coord*)malloc(sizeof(t_coord))))
		return (1);
	newelm->x = x;
	newelm->y = y;
	newelm->next = NULL;
	if (!*alst)
		*alst = newelm;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = newelm;
	}
	return (0);
}

void	tetradd(t_coord *coord, char alph, t_tetr **alst)
{
	t_tetr	*newelm;
	t_tetr	*cur;

	cur = *alst;
	if (!(newelm = (t_tetr*)malloc(sizeof(t_tetr))))
		error(*alst, NULL);
	newelm->coord = coord;
	newelm->alph = alph;
	newelm->next = NULL;
	if (!*alst)
		*alst = newelm;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = newelm;
	}
}
