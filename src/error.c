/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:19:56 by kdune             #+#    #+#             */
/*   Updated: 2019/09/21 20:22:03 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_lst(t_tetr *tetr)
{
	t_tetr	*tmp_tetr;
	t_coord	*tmp_coord;
	t_coord	*tmp_begincoord;

	while (tetr)
	{
		tmp_begincoord = tetr->coord;
		while (tmp_begincoord)
		{
			tmp_coord = tmp_begincoord;
			tmp_begincoord = tmp_begincoord->next;
			free(tmp_coord);
		}
		tmp_tetr = tetr;
		tetr = tetr->next;
		free(tmp_tetr);
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error(t_tetr *tetr, char **map)
{
	if (tetr)
		free_lst(tetr);
	if (map)
		free_map(map);
	ft_putstr("error\n");
	exit(1);
}
