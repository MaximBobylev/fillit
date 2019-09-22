/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbits <hbits@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:25:40 by hbits             #+#    #+#             */
/*   Updated: 2019/09/21 22:40:51 by hbits            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_strings(char *buf)
{
	int string_number;

	string_number = 0;
	while (string_number <= 3)
	{
		if (check_string(buf, string_number))
			return (1);
		string_number++;
	}
	return (0);
}

int	check_newline(char *buf)
{
	if (buf[20] != '\n')
		return (1);
	return (0);
}

int	check_string(char *buf, int string_number)
{
	int i;
	int k;

	k = 0;
	i = string_number * 5;
	while (k <= 3)
	{
		if (VAL_SYMBOLS(buf[i]))
			return (1);
		i++;
		k++;
	}
	if (buf[i] != '\n')
		return (1);
	return (0);
}

int	validate(char *buf, int bt)
{
	if (bt == 21)
	{
		if (check_strings(buf))
			return (1);
		if (check_newline(buf))
			return (1);
	}
	if (bt == 20)
	{
		if (check_strings(buf))
			return (1);
	}
	if (check_hash(buf, bt))
		return (1);
	return (0);
}

int	check_hash(char *buf, int bt)
{
	int		i;
	int		count_links;
	int		count_hash;

	count_links = 0;
	count_hash = 0;
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			if (i + 1 < bt)
				if (buf[i + 1] == '#')
					count_links++;
			if (i + 5 < bt)
				if (buf[i + 5] == '#')
					count_links++;
			count_hash++;
		}
	}
	if (count_hash != 4 || count_links < 3)
		return (1);
	return (0);
}
