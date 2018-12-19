/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:43:57 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/19 12:16:06 by zfaria           ###   ########.fr       */
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
	if (type == Invalid)
		ft_putendl("error");
	exit (-1);
}

int			main(int argc, char **argv)
{
	int			fd;
	char		buf[22];
	t_etromino	*tetrominos;
	char		**tmp_tetromino;

	if (argc != 2)
		die(Argc);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		die(Open);
	if (read(fd, buf, 0) < 0)
		die(Read);
	tetrominos = 0;
	while (read(fd, buf, 21))
	{
		buf[21] = '\0';
		tmp_tetromino = verify_tetrimino(buf);
		if (tmp_tetromino == 0)
			die(Invalid);
		if (tetrominos == 0)
			tetrominos = list_new(tmp_tetromino);
		else
			list_append(tetrominos, tmp_tetromino);
	}

	t_game_board *testmap = map_init(5);
	map_print(testmap);
	map_free(testmap);

	/*			bullshit			*/
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
