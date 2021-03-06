/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_neg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 05:52:05 by macuguen          #+#    #+#             */
/*   Updated: 2017/11/12 01:22:27 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_neg(int *n)
{
	if (*n < 0)
	{
		*n = *n * -1;
		return (1);
	}
	else
		return (0);
}
