/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:51 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 16:45:33 by wstygg           ###   ########.fr       */
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
		lst->next = walls[i].textures;
	}
}

static t_texture	**make_tex(const char *path, SDL_PixelFormat *fmt)
{
	register int	i;
	SDL_Surface		*opt;
	SDL_Surface		*surf;
	t_texture		**texture;

	if (!(surf = IMG_Load(path)))
		ft_crash(SDL_GetError());
	if (!(opt = SDL_ConvertSurface(surf, fmt, 0)))
		ft_crash(SDL_GetError());
	texture = ft_malloc(sizeof(t_texture*) * 4);
	i = -1;
	while (++i < 4)
	{
		texture[i] = ft_malloc(sizeof(t_texture));
		texture[i]->w = opt->w;
		texture[i]->h = opt->h;
		texture[i]->pixels = ft_malloc(sizeof(unsigned) * opt->w * opt->h);
		ft_memcpy(texture[i]->pixels,
				opt->pixels, opt->w * opt->h * sizeof(int));
	}
	SDL_FreeSurface(opt);
	SDL_FreeSurface(surf);
	return (texture);
}

static t_list		*read_all_by_name(const char *path, SDL_PixelFormat *fmt)
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

static t_texture	**create_mega_texture(const char *path,
											SDL_PixelFormat *fmt)
{
	register int	i;
	register int	j;
	char			*str;
	t_texture		**to_free;
	t_texture		**mega_texture;

	i = -1;
	mega_texture = ft_malloc(sizeof(t_texture*) * 4);
	while (++i < 4 && (j = -1))
	{
		if (!(str = ft_strjoin(ft_strjoin(ft_strjoin(path, "_", 0),
								ft_itoa(i + 1), 3), ".png", 1)))
			ft_crash("Malloc error");
		if (check_file(str, IS_E) < 1)
			ft_crash("Rikardo %s is missing!!!", str);
		to_free = make_tex(str, fmt);
		mega_texture[i] = to_free[i];
		while (++j < 4)
			if (j != i && ft_free_r(to_free[j]->pixels))
				free(to_free[j]);
		free(str);
		free(to_free);
	}
	return (mega_texture);
}

void				walls_init(t_wall *w, SDL_PixelFormat *fmt,
									const t_map map)
{
	if (check_for_symbol(CHAR_WALL_1, map))
		w[0].textures = list_add_back(w[0].textures,
				make_tex("Textures/wall.png", fmt));
	if (check_for_symbol(CHAR_WALL_2, map))
		w[1].textures = list_add_back(w[1].textures,
				make_tex("Textures/wood.png", fmt));
	if (check_for_symbol(CHAR_WALL_3, map))
		w[2].textures = read_all_by_name("Textures/dance_1/flex", fmt);
	if (check_for_symbol(CHAR_WALL_4, map))
		w[3].textures = read_all_by_name("Textures/dance_2/flex", fmt);
	if (check_for_symbol(CHAR_WALL_5, map))
		w[4].textures = read_all_by_name("Textures/dance_3/flex", fmt);
	if (check_for_symbol(CHAR_WALL_6, map))
		w[5].textures = read_all_by_name("Textures/dance_4/flex", fmt);
	if (check_for_symbol(CHAR_WALL_7, map))
		w[6].textures = list_add_back(w[6].textures,
				create_mega_texture("Textures/Rikardo/mega_flex", fmt));
	make_cycle_lists(w);
}