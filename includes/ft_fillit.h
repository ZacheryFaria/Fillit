/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:50:40 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/21 09:50:50 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

enum			e_usage_types
{
	Argc,
	Open,
	Read,
	Invalid_Tetromino
};

typedef struct	s_t
{
	char		**data;
	struct s_t	*next;
}				t_etromino;

typedef struct	s_game_board
{
	char		**map;
	int			size;
}				t_game_board;

/*
** ****** verify ******
*/
int				verify_tetromino(char **str);
int				verify_block(char *str);

/*
** ****** list ********
*/
t_etromino		*list_new(char **content);
void			list_append(t_etromino *list, char **content);
void			list_iter(t_etromino *a_very_posh_lamp, void (*f)(char **elem));

/*
** ****** map ******
*/
void			map_free(t_game_board *map);
t_game_board	*map_init(int size);
int				map_startsize(int pieces);
int				map_print(t_game_board *map);

void			tetris_trim(char **piece);

#endif
