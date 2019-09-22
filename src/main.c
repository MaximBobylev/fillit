/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:11:53 by kdune             #+#    #+#             */
/*   Updated: 2019/09/21 20:22:46 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int arc, char **arv)
{
	t_tetr	*tetr;
	int		count_tetr;
	int		fd;

	if (arc != 2)
		error(NULL, NULL);
	tetr = NULL;
	if ((fd = open(arv[1], O_RDONLY)) == -1)
		error(NULL, NULL);
	count_tetr = input(fd, &tetr);
	if (close(fd) == -1)
		error(tetr, NULL);
	read_map(tetr, count_tetr);
	return (0);
}
