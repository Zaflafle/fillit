/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_fillit_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:18:04 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/29 20:23:35 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft/libft.h"

int		fillit_sqrt(int n, int *nb_tetri_set, char **square)
{
	int		res;

	res = 1;
	while (res * res < n)
		++res;
	*nb_tetri_set = 0;
	*square = NULL;
	return (res);
}

void	print_fillit_square(char *square, int square_size)
{
	int		i;
	int		j;

	i = 0;
	while (i < square_size)
	{
		j = 0;
		while (j < square_size)
		{
			ft_putchar(square[i * square_size + j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}

void	reset_datas(t_tetri *t, int nb_tetri, int *nb_tetri_set)
{
	int		index;

	index = 0;
	while (index < nb_tetri)
	{
		t[index].x = POSITION_NOT_SET;
		t[index].y = POSITION_NOT_SET;
		++index;
	}
	*nb_tetri_set = 0;
}
