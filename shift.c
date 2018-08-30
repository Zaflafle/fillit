/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:24:33 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/29 20:34:00 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "fillit.h"

static t_bool	is_top_shifted(char tetri[4][4])
{
	size_t	col;

	col = 0;
	while (col < 4)
	{
		if (tetri[0][col] == '#')
			return (TRUE);
		++col;
	}
	return (FALSE);
}

static t_bool	is_left_shifted(char tetri[4][4])
{
	size_t	line;

	line = 0;
	while (line < 4)
	{
		if (tetri[line][0] == '#')
			return (TRUE);
		++line;
	}
	return (FALSE);
}

static void		shift_to_left(char tetri[4][4])
{
	size_t	line;
	size_t	col;

	line = 0;
	while (line < 4)
	{
		col = 0;
		while (col < 3)
		{
			tetri[line][col] = tetri[line][col + 1];
			++col;
		}
		tetri[line][3] = '.';
		++line;
	}
}

static void		shift_to_top(char tetri[4][4])
{
	size_t	line;
	size_t	col;

	col = 0;
	while (col < 4)
	{
		line = 0;
		while (line < 3)
		{
			tetri[line][col] = tetri[line + 1][col];
			++line;
		}
		tetri[3][col] = '.';
		++col;
	}
}

void			shift_top_left(char tetri[4][4])
{
	while (is_left_shifted(tetri) != TRUE)
		shift_to_left(tetri);
	while (is_top_shifted(tetri) != TRUE)
		shift_to_top(tetri);
}
