/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:26:01 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/22 21:08:20 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				render_clear(const Uint32 roof_c, const Uint32 floor_c,
									unsigned pixels[WIDTH * HEIGHT])
{
	register int	h;
	register int	w;

	h = -1;
	while (++h < HEIGHT && (w = -1))
		while (++w < WIDTH)
			pixels[w + h * WIDTH] = (h < HEIGHT_H) ? roof_c : floor_c;
}

static void			keys_init(int keys[SDL_NUM_SCANCODES])
{
	register int	i;

	i = -1;
	while (++i < SDL_NUM_SCANCODES)
		keys[i] = 0;
}

static void			functions_init(t_sdl *sdl)
{
	register int	i;

	i = -1;
	while (++i < SDL_NUM_SCANCODES)
		sdl->do_key[i] = NULL;
	sdl->do_key[SDL_SCANCODE_UP] = move_forward;
	sdl->do_key[SDL_SCANCODE_DOWN] = move_backward;
	sdl->do_key[SDL_SCANCODE_LEFT] = angle_left;
	sdl->do_key[SDL_SCANCODE_RIGHT] = angle_right;
	sdl->do_key[SDL_SCANCODE_KP_PLUS] = add_dist_or_step;
	sdl->do_key[SDL_SCANCODE_KP_MINUS] = sub_dist_or_step;
}

void				sdl_init(t_sdl *sdl, t_wolf *wolf)
{
	sdl->running = 1;
	sdl->show_fps = 1;
	functions_init(sdl);
	keys_init(sdl->keys);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (ft_crash(SDL_GetError()));
	if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_WEBP) &
			(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_WEBP)))
		return (ft_crash(SDL_GetError()));
	if (TTF_Init() != 0)
		return (ft_crash(SDL_GetError()));
	if (!(sdl->font = TTF_OpenFont(".OpenSans.ttf", HEIGHT / 25)))
		return (ft_crash(SDL_GetError()));
	if (!(sdl->win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		return (ft_crash(SDL_GetError()));
	if (!(sdl->surf = SDL_GetWindowSurface(sdl->win)))
		return (ft_crash(SDL_GetError()));
	wolf->pixels = sdl->surf->pixels;
	wolf->walls = ft_malloc(sizeof(t_wall) * WALLS_N);
	walls_init(wolf->walls, sdl->surf->format, wolf->map);
}
