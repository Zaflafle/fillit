/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_init_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:52:25 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/29 21:14:49 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static size_t	get_nb_tetri(char *file_content)
{
	size_t	nb_tetri;

	nb_tetri = 1;
	while (*file_content != '\0')
	{
		if (*file_content == '\n' && *(file_content + 1) == '\n')
			++nb_tetri;
		++file_content;
	}
	return (nb_tetri);
}

static void		insert_tetri(char tetri[4][4], char *file_content, size_t index)
{
	size_t	index2;
	size_t	line;
	size_t	col;

	index2 = (index == 0) ? (0) : (index * 21);
	line = 0;
	col = 0;
	while (1)
	{
		if (file_content[index2] == '\n' && (file_content[index2 + 1] == '\n'
		|| file_content[index2 + 1] == '\0'))
			break ;
		if (col == 4)
		{
			col = 0;
			++line;
		}
		if (file_content[index2] != '\n')
		{
			tetri[line][col] = file_content[index2];
			++col;
		}
		++index2;
	}
	shift_top_left(tetri);
}

t_tetri			*create_and_init_t(char *file_content, int *nb_tetri)
{
	t_tetri		*t;
	int			index;

	*nb_tetri = get_nb_tetri(file_content);
	if ((t = malloc(sizeof(struct s_tetri) * (*nb_tetri))) == NULL)
		exit(EXIT_FAILURE);
	index = 0;
	while (index < *nb_tetri)
	{
		t[index].x = POSITION_NOT_SET;
		t[index].y = POSITION_NOT_SET;
		insert_tetri(t[index].tetri, file_content, index);
		++index;
	}
	return (t);
}
