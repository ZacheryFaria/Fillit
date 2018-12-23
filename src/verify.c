/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:45:38 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/20 12:24:51 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>
#include <string.h>
#include <stdlib.h>

int	verify_block(char *str)
{
	int hash;
	int dot;
	int nl;
	int i;

	hash = 0;
	dot = 0;
	nl = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '\n')
			nl++;
		if (str[i] == '.')
			dot++;
		if (str[i] == '#')
			hash++;
		i++;
	}
	return (hash == 4 && dot == 12 && nl == 4);
}

static int	verify_adjacent(char **piece, int x, int y)
{
	int valid;

	valid = 0;
	if (y > 0)
		if (piece[y - 1][x] == '#')
			valid++;
	if (y < 3)
		if (piece[y + 1][x] == '#')
			valid++;
	if (x > 0)
		if (piece[y][x - 1] == '#')
			valid++;
	if (x < 3)
		if (piece[y][x + 1] == '#')
			valid++;
	return (valid);
}

int	verify_tetromino(char **piece)
{
	int x;
	int y;
	int valid;

	x = 0;
	y = 0;
	valid = 0;
	while (y <= 3)
	{
		if (piece[y][x] == '#')
		{
			valid += verify_adjacent(piece, x, y);
		}
		if (x == 3)
		{
			x = -1;
			y++;
		}
		x++;
	}
	return (valid > 5);
	free(piece);
}
