/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbits <hbits@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:55:20 by kdune             #+#    #+#             */
/*   Updated: 2019/09/21 22:39:58 by hbits            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	input_tetr(t_tetr **tetr, char *buf, char alph)
{
	t_coord	*coord;
	int		x;
	int		y;
	int		first_hash;
	int		i;

	i = -1;
	coord = NULL;
	first_hash = 0;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			if (first_hash || !(first_hash = 1))
				if (coordadd(x, y, &coord))
					error(*tetr, NULL);
			x = 0;
			y = 0;
		}
		if (first_hash && buf[i] == '\n' && (++y))
			x -= 5;
		x++;
	}
	tetradd(coord, alph, tetr);
}

int		input(int fd, t_tetr **tetr)
{
	char	buf[BUF_SIZE + 1];
	int		bt;
	int		count_tetr;
	char	alph;

	count_tetr = 0;
	alph = 'A';
	while ((bt = read(fd, buf, BUF_SIZE)))
	{
		if (bt < 20)
			error(*tetr, NULL);
		buf[bt] = 0;
		if (validate(buf, bt))
			error(*tetr, NULL);
		input_tetr(tetr, buf, alph++);
		count_tetr++;
		if (bt == 20)
			break ;
	}
	if (bt == 0)
		error(*tetr, NULL);
	return (count_tetr);
}
