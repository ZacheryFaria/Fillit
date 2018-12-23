/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:57 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/23 13:24:30 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_fillit.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	die(int type)
{
	if (type == Argc)
		ft_putendl("usage: ./fillit filename");
	if (type == Open)
		ft_putendl("can not open file");
	if (type == Read)
		ft_putendl("can not read file");
	if (type == Invalid_Tetromino)
		ft_putendl("error");
	exit (-1);
}

int			main(int argc, char **argv)
{
	int			fd;
	char		buf[22];
	int			bread;
	t_etromino	*tetrominos;

	if (argc != 2)
		die(Argc);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		die(Open);
	if (read(fd, buf, 0) < 0)
		die(Read);
	tetrominos = 0;
	while ((bread = read(fd, buf, 21)) >= 20)
	{
		buf[21] = '\0';
		if ( !verify_block(buf) || !verify_tetromino(ft_strsplit(buf, '\n')))
			die(Invalid_Tetromino);
		else
		{
			if (tetrominos == 0)
				tetrominos = list_new(ft_strsplit(buf, '\n'));
			else
				list_append(tetrominos, ft_strsplit(buf, '\n'));
		}
	}

	/*			bullshit			*/
	#define T_PRINT_PCS
	#ifdef T_PRINT_PCS
		while (tetrominos)
		{
			puts("new piece");
			for (int i = 0; tetrominos->data[i]; i++)
				puts(tetrominos->data[i]);
			puts("");
			tetrominos = tetrominos->next;
		}
	#endif
	#ifdef T_PRINT_MAP
		char **map = ft_strsplit("....\n##..\n.##.\n....", '\n');
		print_map(map);
	#endif
	/*			bullshit			*/



	close(fd);
	return (0);
}
