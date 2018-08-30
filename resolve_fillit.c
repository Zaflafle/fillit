/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:57:36 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/29 20:33:35 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static void		init_square(char **square, int square_size)
{
	size_t	index;

	free(*square);
	index = square_size * square_size;
	if ((*square = malloc(index)) == NULL)
		exit(EXIT_FAILURE);
	while (index > 0)
	{
		(*square)[index - 1] = POSITION_FREE;
		--index;
	}
}

static t_bool	try_put_tetri_in_square(t_tetri *t, char *square,
								int nb_tetri_set, int sz)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((j + t[nb_tetri_set].y >= sz && t[nb_tetri_set].tetri[i][j]
	== POSITION_SET) || (t[nb_tetri_set].tetri[i][j] == POSITION_SET &&
square[(t[nb_tetri_set].x + i) * sz + t[nb_tetri_set].y + j] != POSITION_FREE))
				return (FALSE);
		}
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (t[nb_tetri_set].tetri[i][j] == POSITION_SET)
				square[(t[nb_tetri_set].x + i) * sz +
				t[nb_tetri_set].y + j] = nb_tetri_set + 'A';
	}
	return (TRUE);
}

static t_bool	put_tetri_in_square(t_tetri *t, char *square,
							int nb_tetri_set, int square_size)
{
	int		i;
	int		j;
	int		old_x;

	old_x = t[nb_tetri_set].x;
	i = (old_x == POSITION_NOT_SET) ? (0) : old_x;
	while (i < square_size)
	{
		j = (i == old_x) ? (t[nb_tetri_set].y) : (0);
		while (j < square_size)
		{
			t[nb_tetri_set].x = i;
			t[nb_tetri_set].y = j;
			if (try_put_tetri_in_square(t, square, nb_tetri_set, square_size)
			== TRUE)
			{
				return (TRUE);
			}
			++j;
		}
		++i;
	}
	t[nb_tetri_set].x = POSITION_NOT_SET;
	t[nb_tetri_set].y = POSITION_NOT_SET;
	return (FALSE);
}

static void		remove_last_tetri(t_tetri *t, char *square, int nb_tetri_set,
															int square_size)
{
	int		i;
	int		j;
	int		square_total_size;

	i = t[nb_tetri_set].x;
	square_total_size = square_size * square_size;
	while (i < t[nb_tetri_set].x + 4)
	{
		j = t[nb_tetri_set].y;
		while (j < t[nb_tetri_set].y + 4)
		{
			if (i * square_size + j < square_total_size
			&& square[i * square_size + j] == nb_tetri_set + 'A')
				square[i * square_size + j] = POSITION_FREE;
			++j;
		}
		++i;
	}
	if (t[nb_tetri_set].y == square_size - 1)
	{
		++(t[nb_tetri_set].x);
		t[nb_tetri_set].y = POSITION_NOT_SET;
	}
	else
		++(t[nb_tetri_set].y);
}

void			resolve_fillit(t_tetri *t, int nb_tetri)
{
	int		square_size;
	int		nb_tetri_set;
	char	*square;

	square_size = fillit_sqrt(nb_tetri * 4, &nb_tetri_set, &square);
	while (nb_tetri_set < nb_tetri)
	{
		reset_datas(t, nb_tetri, &nb_tetri_set);
		init_square(&square, square_size);
		while (nb_tetri_set < nb_tetri && nb_tetri_set >= 0)
		{
			if (put_tetri_in_square(t, square, nb_tetri_set, square_size) == 1)
				++nb_tetri_set;
			else
			{
				--nb_tetri_set;
				if (nb_tetri_set >= 0)
					remove_last_tetri(t, square, nb_tetri_set, square_size);
			}
			if (nb_tetri_set < 0)
				++square_size;
		}
	}
	print_fillit_square(square, square_size);
	free(square);
}
