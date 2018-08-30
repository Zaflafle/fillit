/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:42:57 by cyfermie          #+#    #+#             */
/*   Updated: 2017/12/09 18:44:14 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static t_bool	check_file_format(char *file_content)
{
	int		line;
	int		i;

	line = 0;
	while (*file_content != '\0' && ++line)
	{
		if (line % 5 == 0)
		{
			if (*file_content != '\n')
				return (FALSE);
		}
		else
		{
			i = 0;
			while (*file_content != '\n')
			{
				++file_content;
				++i;
			}
			if (i != 4)
				return (FALSE);
		}
		++file_content;
	}
	return (TRUE);
}

static t_bool	check_file_len(char *file_content)
{
	size_t	possible_len_values[26];
	int		i;
	size_t	value;
	size_t	file_len;

	file_len = ft_strlen(file_content);
	value = -1;
	i = -1;
	while (++i < 26)
	{
		possible_len_values[i] = value + 21;
		value += 21;
	}
	i = -1;
	while (++i < 26)
		if (file_len == possible_len_values[i])
			return (TRUE);
	return (FALSE);
}

static t_bool	check_content(char *file_content)
{
	int		hashtag;
	int		dot;
	int		newline;

	hashtag = 0;
	dot = 0;
	newline = 0;
	if (*file_content == '\n')
		return (FALSE);
	while (*file_content != '\0')
	{
		if (*file_content != '#' && *file_content != '.'
		&& *file_content != '\n')
			return (FALSE);
		if (*file_content == '#')
			hashtag = 1;
		else if (*file_content == '.')
			dot = 1;
		else if (*file_content == '\n')
			newline = 1;
		++file_content;
	}
	if (hashtag == 0 || dot == 0 || newline == 0)
		return (FALSE);
	return (TRUE);
}

static t_bool	check_tetri(char *file_content)
{
	while (*file_content != '\0')
	{
		if (*file_content == '#')
		{
			if (check_one_tetri(file_content) == FALSE)
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
		}
		++file_content;
	}
	return (TRUE);
}

t_bool			check_file_validity(char *file_content)
{
	if (check_file_len(file_content) == FALSE)
		return (FALSE);
	if (check_content(file_content) == FALSE)
		return (FALSE);
	if (check_file_format(file_content) == FALSE)
		return (FALSE);
	if (check_tetri(file_content) == FALSE)
		return (FALSE);
	if (bug_retry_mdr(file_content) == FALSE)
		return (FALSE);
	return (TRUE);
}
