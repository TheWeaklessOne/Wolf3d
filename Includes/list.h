#ifndef WOLF3D_LIST_H
#define WOLF3D_LIST_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

t_list					*list_add_at(t_list *lst, int at, void *content);
t_list					*list_remove_at(t_list *lst, int at, int to_free);
t_list					*list_at(t_list *lst, int at);
t_list					*list_remove_front(t_list *list, int to_free);
t_list					*list_remove_back(t_list *list, int to_free);
t_list					*list_add_front(t_list *list, void *content);
t_list					*list_add_back(t_list *list, void *content);
t_list					*list_create(void *content);
t_list					*list_remove_all(t_list *list, int to_free);
int						list_length(t_list *list);

void					ft_crash(const char *msg, ...);

#endif
