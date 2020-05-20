/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:27:26 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 19:27:26 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_LIST_H
# define WOLF3D_LIST_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

t_list					*list_at(t_list *lst, int at);
t_list					*list_add_back(t_list *list, void *content);
t_list					*list_create(void *content);

void					ft_crash(const char *msg, ...);

#endif
