/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 00:23:19 by kdune             #+#    #+#             */
/*   Updated: 2019/09/21 21:21:57 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		puttetr(t_mapsize map_s, int x, int y, t_coord *coord)
{
	int		xc;
	int		yc;

	if (map_s.map[y][x])
		return (1);
	xc = coord->x;
	yc = coord->y;
	if ((x + xc < 0 || x + xc > map_s.size - 1)
	|| (y + yc < 0 || y + yc > map_s.size - 1) || (map_s.map[y + yc][x + xc]))
		return (1);
	if (coord->next)
	{
		if (!puttetr(map_s, x + xc, y + yc, coord->next))
			map_s.map[y][x] = map_s.alph;
		else
			return (1);
	}
	else
	{
		map_s.map[y][x] = map_s.alph;
		map_s.map[y + yc][x + xc] = map_s.alph;
	}
	return (0);
}

void	remove_tetr(char **map, int x, int y, t_coord *coord)
{
	int xc;
	int yc;

	xc = coord->x;
	yc = coord->y;
	if (coord->next)
	{
		remove_tetr(map, x + xc, y + yc, coord->next);
		map[y][x] = 0;
	}
	else
	{
		map[y][x] = 0;
		map[y + yc][x + xc] = 0;
		return ;
	}
	return ;
}

int		recursive_map(char **map, int size, t_tetr *tetr)
{
	int			x;
	int			y;
	int			tetron;
	t_mapsize	map_s;

	x = 0;
	y = 0;
	map_s.map = map;
	map_s.size = size;
	map_s.alph = tetr->alph;
	while ((tetron = puttetr(map_s, x, y, tetr->coord))
	|| (tetr->next && recursive_map(map, size, tetr->next)))
	{
		if (!tetron)
			remove_tetr(map, x, y, tetr->coord);
		if (x < size - 1)
			x++;
		else if (!(x = 0))
		{
			y++;
			if (y == size)
				return (1);
		}
	}
	return (0);
}
