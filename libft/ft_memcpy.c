/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:12:23 by macuguen          #+#    #+#             */
/*   Updated: 2017/11/12 02:17:38 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*ptr;

	if (!dest && !src && !n)
		return (0);
	i = 0;
	str = (char*)src;
	ptr = (char*)dest;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}
