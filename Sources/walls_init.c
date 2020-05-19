/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:51 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/19 15:15:56 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			make_cycle_lists(t_wall *walls)
{
	register int	i;
	unsigned		len;
	t_list			*lst;

	i = -1;
	while (++i < WALLS_N)
	{
		len = 1;
		lst = walls[i].textures;
		if (!lst)
			continue ;
		while (lst->next)
		{
			len++;
			lst = lst->next;
		}
		walls[i].frames = len;
		walls[i].fps = 1000.0 / ((len > 10) ? 10 : len);
		lst->next = walls[i].textures;
	}
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

t_list				*read_all_by_name(const char *path, SDL_PixelFormat *fmt)
{
	register int	a;
	t_list			*ret;
	char			*str;

	a = 0;
	ret = NULL;
	while (++a)
	{
		str = ft_strjoin(ft_strjoin(ft_strjoin(path, "_", 0),
				ft_itoa(a), 3), ".png", 1);
		if (!str)
			ft_crash("Malloc error");
		if (check_file(str, IS_E) < 1)
		{
			free(str);
			return (ret);
		}
		ret = list_add_back(ret, make_tex(str, fmt));
		free(str);
	}
	return (ret);
}

static int			check_for_symbol(const char c, const t_map map)
{
	register int	w;
	register int	h;

	h = -1;
	while (++h < map.map_h && (w = -1))
		while (++w < map.map_w)
			if (map.map[h][w] == c)
				return (1);
	return (0);
}

void				walls_init(t_wall *w, SDL_PixelFormat *fmt,
									const t_map map)
{
	register int	i;

	i = -1;
	while (++i < WALLS_N)
	{
		w->frames = 0;
		w->textures = NULL;
	}
	if (check_for_symbol(CHAR_WALL_1, map))
		w[0].textures = list_add_back(w[0].textures, make_tex("Textures/wall_128.png", fmt));
	if (check_for_symbol(CHAR_WALL_2, map))
		w[1].textures = list_add_back(w[1].textures, make_tex("Textures/wood_128.png", fmt));
	if (check_for_symbol(CHAR_WALL_3, map))
		w[2].textures = read_all_by_name("Textures/dance_1/flex", fmt);
	make_cycle_lists(w);
}