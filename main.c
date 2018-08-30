/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:51:23 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/29 19:52:06 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	char		*file_content;
	t_tetri		*t;
	int			nb_tetri;

	if (argc != 2)
	{
		ft_putstr("usage: fillit tetriminos_file\n");
		return (0);
	}
	file_content = get_file_content(argv[1]);
	if (check_file_validity(file_content) == FALSE)
	{
		ft_putstr("error\n");
		free(file_content);
		return (0);
	}
	t = create_and_init_t(file_content, &nb_tetri);
	free(file_content);
	resolve_fillit(t, nb_tetri);
	free(t);
	return (EXIT_SUCCESS);
}
