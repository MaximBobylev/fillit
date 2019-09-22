/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:21:45 by kdune             #+#    #+#             */
/*   Updated: 2019/04/16 19:22:37 by kdune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*minint(void)
{
	char	*value;

	if (!(value = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	value[0] = '-';
	value[1] = '2';
	value[2] = '1';
	value[3] = '4';
	value[4] = '7';
	value[5] = '4';
	value[6] = '8';
	value[7] = '3';
	value[8] = '6';
	value[9] = '4';
	value[10] = '8';
	value[11] = '\0';
	return (value);
}

static int	findlen(int n)
{
	int		len;
	int		i;
	int		tmp;

	len = 1;
	i = 0;
	tmp = n;
	while (tmp / 10 != 0)
	{
		tmp /= 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		len;

	if (n == -2147483648)
		return (minint());
	len = findlen(n);
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len] = '\0';
	len--;
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
	}
	else if (n == 0)
		num[0] = '0';
	while (n > 0)
	{
		num[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (num);
}
