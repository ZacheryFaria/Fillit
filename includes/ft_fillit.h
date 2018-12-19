/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:50:40 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/18 19:08:03 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

enum usage_types{Argc,Open,Read};

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetromino
{
	char				**data;
	struct s_tetromino	*next;
}				t_etromino;

/*
** ****** verify ******
*/
int				verify_piece(char **str);
int				verify_block(char *str);
int				verify_adjacent(char **piece, int x, int y);
/*
** ****** print  ******
*/
int				print_map(char **map);

/*
** ****** list ********
*/
t_etromino	*list_new(char *content);
void		list_append(t_etromino *list, char *content);

#endif
