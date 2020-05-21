/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:05:44 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 18:50:44 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				map_render(const t_map map, unsigned *pixels)
{
	register int	i;
	register int	j;
	unsigned		rect_x;
	unsigned		rect_y;

	j = -1;
	while (++j < map.map_h && (i = -1))
		while (++i < map.map_h)
		{
			rect_x = i * map.rect_w;
			rect_y = j * map.rect_h;
			if (map.map[j][i] != CHAR_EMPTY)
				draw_rectangle((t_rect){rect_x, rect_y, map.rect_w, map.rect_h},
						0x424242, pixels);
		}
}

int					render_thread(void *data)
{
	register int	i;
	const t_thread	thread = *(t_thread*)data;
	const int		min = WIDTH / THREADS_N * thread.thread_n;
	const int		max = WIDTH / THREADS_N * (thread.thread_n + 1);

	i = min - 1;
	while (++i < max)
		cast_rays(
				thread.wolf,
				thread.wolf->player.a - thread.wolf->player.fov / 2 +
					thread.wolf->player.fov * i / WIDTH, i,
				thread.pixels);
	return (0);
}

static void			render(t_wolf *wolf, unsigned *pixels)
{
	register int	i;
	t_thread		thread[THREADS_N];
	SDL_Thread		*threads[THREADS_N];

	i = -1;
	while (++i < THREADS_N)
	{
		thread[i].wolf = wolf;
		thread[i].pixels = pixels;
		thread[i].thread_n = i;
		if (!(threads[i] = SDL_CreateThread(render_thread, NULL, thread + i)))
			ft_crash("Can't create a thread - [%d]!", i);
	}
	while (--i > -1)
		SDL_WaitThread(threads[i], NULL);
	if (wolf->show_map)
		map_render(wolf->map, pixels);
}

static int			next_texture(t_wall *walls)
{
	register int	i;
	t_wall			wall;

	i = -1;
	while (++i < WALLS_N)
	{
		wall = walls[i];
		if (wall.frames > 1)
			walls[i].textures = walls[i].textures->next;
	}
	return (1);
}

int					main(int argc, char *argv[])
{
	SDL_Event		e;
	t_sdl			sdl;
	t_wolf			wolf;

	wolf_init(&wolf, argc, argv);
	sdl_init(&sdl, &wolf);
	while (sdl.running)
	{
		ft_time()->step = SDL_GetTicks();
		render_clear(wolf.roof_c, wolf.floor_c, wolf.pixels);
		render(&wolf, wolf.pixels);
		SDL_UpdateWindowSurface(sdl.win);
		ft_time()->delta = SDL_GetTicks() - ft_time()->step;
		ft_time()->since_frame += ft_time()->delta;
		if (ft_time()->since_frame >= ANIM_TIME && next_texture(wolf.walls))
			ft_time()->since_frame -= ANIM_TIME;
		if (MIN_FRAME_TIME > ft_time()->delta)
			SDL_Delay(MIN_FRAME_TIME - ft_time()->delta);
		while (SDL_PollEvent(&e))
			manage_event(e, &sdl, &wolf);
		manage_keys(&sdl, &wolf);
	}
	sdl_quit(&sdl);
	exit(0);
}
