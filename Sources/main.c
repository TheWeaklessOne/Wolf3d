/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:05:44 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/19 00:41:55 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			map_render(const t_map map, unsigned *pixels)
{
	register int	i;
	register int	j;

	j = -1;
	while (++j < map.map_h && (i = -1))
		while (++i < map.map_h)
		{
			unsigned rect_x = i * map.rect_w;
			unsigned rect_y = j * map.rect_h;
			if (map.map[j][i] != CHAR_EMPTY)
				draw_rectangle((t_rect){rect_x, rect_y, map.rect_w, map.rect_h},
						0x424242, pixels);
		}
}

static void			render(t_wolf wolf, unsigned *pixels)
{
	register int	i;

	i = -1;
	while (++i < WIDTH)
	{
		cast_rays(
		wolf,
		wolf.player.a - wolf.player.fov / 2 + wolf.player.fov * i / WIDTH,
		i,
		pixels);
	}
	if (wolf.show_map)
		map_render(wolf.map, pixels);
}

int								main(int argc, char *argv[])
{
	SDL_Event		e;
	t_sdl			sdl;
	t_wolf			wolf;

	wolf_init(&wolf, argc, argv);
	sdl_init(&sdl, &wolf);
	while (sdl.running)
	{
		while (SDL_PollEvent(&e))
			manage_event(e, &sdl, &wolf);
		manage_keys(&sdl, &wolf);
		render_clear(wolf.pixels);
		render(wolf, wolf.pixels);
		SDL_UpdateWindowSurface(sdl.win);
	}
	sdl_quit(&sdl);
	exit(0);
}
