/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:14:59 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/19 16:20:36 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list			*list_at(t_list *lst, int at)
{
	t_list		*ret;
	int			i;

	if (!lst)
		return (NULL);
	if (at <= 0)
		return (lst);
	ret = lst;
	i = 1;
	while (lst->next && i < at)
	{
		lst = lst->next;
		i++;
	}
	if (i == at)
		return (lst);
	return (ret);
}

t_list			*list_add_back(t_list *list, void *content)
{
	t_list		*item;
	t_list		*ret;

	if (!list)
		return (list_create(content));
	ret = list;
	while (list->next)
		list = list->next;
	if (!(item = malloc(sizeof(t_list))))
		ft_crash("Malloc error");
	item->content = content;
	item->next = NULL;
	list->next = item;
	return (ret);
}

t_list			*list_create(void *content)
{
	t_list		*ret;

	if (!(ret = malloc(sizeof(t_list))))
		ft_crash("Malloc error");
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
