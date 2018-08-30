/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:27:26 by cyfermie          #+#    #+#             */
/*   Updated: 2017/12/09 18:43:29 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

struct					s_tetri
{
	int		x;
	int		y;
	char	tetri[4][4];
};
typedef struct s_tetri	t_tetri;

enum					e_bool
{
	FALSE,
	TRUE
};
typedef enum e_bool		t_bool;

# define POSITION_NOT_SET -1
# define POSITION_FREE	 '.'

# define POSITION_SET	 '#'

char					*get_file_content(char *pathname);
t_tetri					*create_and_init_t(char *file_content, int *nb_tetri);
void					shift_top_left(char tetri[4][4]);
void					resolve_fillit(t_tetri *t, int nb_tetri);
int						fillit_sqrt(int n, int *nb_tetri_set, char **square);
void					print_fillit_square(char *square, int square_size);
void					reset_datas(t_tetri *t, int nb_tetri,
						int *nb_tetri_set);
t_bool					check_file_validity(char *file_content);
t_bool					check_one_tetri(char *ptr);
t_bool					bug_retry_mdr(char *file_content);

#endif
