/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 06:22:42 by macuguen          #+#    #+#             */
/*   Updated: 2017/11/12 02:09:10 by macuguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char*)&str[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)&str[i]);
	return (0);
}
