/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:51 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/17 18:12:02 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_texture	*make_tex(const char *path)
{
	SDL_Surface		*surf;
	t_texture		*texture;

	if (!(surf = IMG_Load(path)))
		ft_crash(SDL_GetError());
	texture = ft_malloc(sizeof(t_texture));
	texture->w = surf->w;
	texture->h = surf->h;
	texture->pixels = ft_malloc(sizeof(unsigned) * surf->w * surf->h);
	ft_memcpy(texture->pixels, surf->pixels, surf->w * surf->h * sizeof(int));
	SDL_FreeSurface(surf);
	return (texture);
}

void				walls_init(t_list **walls)
{
	walls[0] = list_add_back(walls[0], make_tex("Textures/wall_128.png"));
	walls[1] = list_add_back(walls[1], make_tex("Textures/rocks_128.png"));
	walls[2] = list_add_back(walls[2], make_tex("Textures/wood_128.png"));
}