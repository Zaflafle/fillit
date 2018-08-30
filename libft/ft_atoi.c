/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 04:00:35 by macuguen          #+#    #+#             */
/*   Updated: 2017/11/12 01:18:16 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int neg;
	int i;
	int result;

	i = 0;
	neg = 0;
	result = 0;
	while ((nptr[i] == '\n') || (nptr[i] == '\t') || (nptr[i] == '\v') ||
	(nptr[i] == ' ') || (nptr[i] == '\f') || (nptr[i] == '\r'))
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		result = result * 10;
		result = result + ((int)nptr[i] - 48);
		i++;
	}
	if (neg == 1)
		return (-result);
	else
		return (result);
}
