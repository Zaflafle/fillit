/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:24:57 by cyfermie          #+#    #+#             */
/*   Updated: 2017/12/09 19:25:36 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	count(char *ptr)
{
	size_t	count;
	size_t	nb_car;

	nb_car = 0;
	count = 0;
	while (nb_car < 20)
	{
		count += *ptr;
		++nb_car;
		++ptr;
	}
	if (count != 732)
		return (FALSE);
	return (TRUE);
}

t_bool			bug_retry_mdr(char *file_content)
{
	while (*file_content != '\0')
	{
		if (count(file_content) == FALSE)
			return (FALSE);
		while (1)
		{
			if (*file_content == '\0')
				return (TRUE);
			if (*file_content == '\n' && *(file_content + 1) == '\n')
			{
				++file_content;
				break ;
			}
			++file_content;
		}
		++file_content;
	}
	return (TRUE);
}

t_bool			check_one_tetri(char *ptr)
{
	size_t	i;

	i = 0;
	if ((ptr[i + 1] == '#' && ptr[i + 5] == '#' && ptr[i + 6] == '#')
	|| (ptr[i + 5] == '#' && ptr[i + 10] == '#' && ptr[i + 15] == '#')
	|| (ptr[i + 1] == '#' && ptr[i + 2] == '#' && ptr[i + 3] == '#')
	|| (ptr[i + 1] == '#' && ptr[i + 6] == '#' && ptr[i + 7] == '#')
	|| (ptr[i + 4] == '#' && ptr[i + 5] == '#' && ptr[i + 9] == '#')
	|| (ptr[i + 1] == '#' && ptr[i + 4] == '#' && ptr[i + 5] == '#')
	|| (ptr[i + 5] == '#' && ptr[i + 6] == '#' && ptr[i + 11] == '#')
	|| (ptr[i + 4] == '#' && ptr[i + 5] == '#' && ptr[i + 6] == '#')
	|| (ptr[i + 1] == '#' && ptr[i + 2] == '#' && ptr[i + 6] == '#')
	|| (ptr[i + 5] == '#' && ptr[i + 6] == '#' && ptr[i + 10] == '#')
	|| (ptr[i + 4] == '#' && ptr[i + 5] == '#' && ptr[i + 10] == '#')
	|| (ptr[i + 5] == '#' && ptr[i + 9] == '#' && ptr[i + 10] == '#')
	|| (ptr[i + 1] == '#' && ptr[i + 5] == '#' && ptr[i + 10] == '#')
	|| (ptr[i + 5] == '#' && ptr[i + 6] == '#' && ptr[i + 7] == '#')
	|| (ptr[i + 1] == '#' && ptr[i + 2] == '#' && ptr[i + 5] == '#')
	|| (ptr[i + 5] == '#' && ptr[i + 10] == '#' && ptr[i + 11] == '#')
	|| (ptr[i + 1] == '#' && ptr[i + 6] == '#' && ptr[i + 11] == '#')
	|| (ptr[i + 1] == '#' && ptr[i + 2] == '#' && ptr[i + 7] == '#')
	|| (ptr[i + 3] == '#' && ptr[i + 4] == '#' && ptr[i + 5] == '#'))
		return (TRUE);
	return (FALSE);
}
