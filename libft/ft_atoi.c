/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:46:01 by kdune             #+#    #+#             */
/*   Updated: 2019/04/16 19:12:31 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MINLONG -922337203685477580
#define RET_MINLONG(ret, ch) (ret == MINLONG && (ch == '9' || ch == '8'))

static long	st_char2int(const char *str, int i, int sign)
{
	long	ret;

	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == -1 && (RET_MINLONG(ret, str[i]) || ret > 0
		|| ret < MINLONG))
			return (0);
		else if (sign == 1 && (RET_MINLONG(ret, str[i]) || ret > 0
		|| ret < MINLONG))
			return (-1);
		else
			ret = ret * 10 - (str[i] - '0');
		i++;
	}
	return ((int)ret * -sign);
}

int			ft_atoi(const char *str)
{
	size_t	i;

	i = 0;
	while (SPACE(str[i]))
		i++;
	if (str[i] == '-')
		return (st_char2int(str, i + 1, -1));
	else if (str[i] == '+')
		return (st_char2int(str, i + 1, 1));
	else
		return (st_char2int(str, i, 1));
}
