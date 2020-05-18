/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:51 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/19 01:52:03 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			make_cycle_list(t_list *list)
{
	t_list			*start;
	t_list			*lst;

	lst = list;
	start = list;
	while (lst->next)
		lst = lst->next;
	lst->next = start;
}

static t_texture	*make_tex(const char *path, SDL_PixelFormat *fmt)
{
	SDL_Surface		*opt;
	SDL_Surface		*surf;
	t_texture		*texture;

	if (!(surf = IMG_Load(path)))
		ft_crash(SDL_GetError());
	if (!(opt = SDL_ConvertSurface(surf, fmt, 0)))
		ft_crash(SDL_GetError());
	texture = ft_malloc(sizeof(t_texture));
	texture->w = opt->w;
	texture->h = opt->h;
	texture->pixels = ft_malloc(sizeof(unsigned) * opt->w * opt->h);
	ft_memcpy(texture->pixels, opt->pixels, opt->w * opt->h * sizeof(int));
	SDL_FreeSurface(opt);
	SDL_FreeSurface(surf);
	return (texture);
}

void				walls_init(t_list **w, SDL_PixelFormat *fmt)
{
	w[0] = list_add_back(w[0], make_tex("Textures/wall_128.png", fmt));
	w[1] = list_add_back(w[1], make_tex("Textures/rocks_128.png", fmt));
	w[1] = list_add_back(w[1], make_tex("Textures/planks_256.png", fmt));
	w[2] = list_add_back(w[2], make_tex("Textures/wood_128.png", fmt));
	make_cycle_list(w[0]);
	make_cycle_list(w[1]);
	make_cycle_list(w[2]);
}