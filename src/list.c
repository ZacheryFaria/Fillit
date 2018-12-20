/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:28:31 by awindham          #+#    #+#             */
/*   Updated: 2018/12/20 10:38:47 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"
#include <stdlib.h>

t_etromino	*list_new(char **content)
{
	t_etromino	*newl;

	if ((newl = malloc(sizeof(*newl))) == 0)
		return (NULL);
	if (content == 0)
		newl->data = 0;
	else
		newl->data = content;
	newl->next = 0;
	return (newl);
}

void		list_append(t_etromino *list, char **content)
{
	t_etromino	*append;

	append = list_new(content);
	while (list->next)
		list = list->next;
	list->next = append;
}

void		list_iter(t_etromino *a_very_posh_lamp, void (*f)(char **elem))
{
	while (a_very_posh_lamp)
	{
		f(a_very_posh_lamp->data);
		a_very_posh_lamp = a_very_posh_lamp->next;
	}
}
