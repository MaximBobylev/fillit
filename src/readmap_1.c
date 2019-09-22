/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 00:23:09 by kdune             #+#    #+#             */
/*   Updated: 2019/09/21 21:34:37 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		create_map(char ***map, int size)
{
	int		i;

	if (*map)
		free_map(*map);
	if (!(*map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (1);
	i = 0;
	while (i < size)
	{
		if (!((*map)[i] = ft_strnew(size)))
			return (1);
		i++;
	}
	(*map)[i] = 0;
	return (0);
}

void	filling_map(char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (!map[i][j])
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	read_map(t_tetr *tetr, int count_tetr)
{
	char	**map;
	int		size;

	size = 2;
	map = NULL;
	while (size * size < count_tetr * 4)
		size++;
	if (create_map(&map, size))
		error(tetr, map);
	while (recursive_map(map, size, tetr))
	{
		size++;
		if (create_map(&map, size + 1))
			error(tetr, map);
	}
	filling_map(map, size);
	print_map(map);
	free_map(map);
	free_lst(tetr);
}
