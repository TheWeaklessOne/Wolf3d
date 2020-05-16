/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:26:01 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/14 10:22:15 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			keys_init(int keys[SDL_NUM_SCANCODES])
{
	register int	i;

	i = -1;
	while (++i < SDL_NUM_SCANCODES)
		keys[i] = 0;
}

void				render_clear(unsigned pixels[WIDTH * HEIGHT])
{
	register int	h;
	register int	w;

	h = -1;
	while (++h < HEIGHT && (w = -1))
		while (++w < WIDTH)
			pixels[w + h * WIDTH] = (h < HEIGHT_H)
					? ROOF_COLOR : FLOOR_COLOR;
}

static void			functions_init(t_sdl *sdl)
{
	register int	i;

	i = -1;
	while (++i < SDL_NUM_SCANCODES)
		sdl->do_key[i] = NULL;
	sdl->do_key[SDL_SCANCODE_W] = move_forward;
	sdl->do_key[SDL_SCANCODE_S] = move_backward;
	sdl->do_key[SDL_SCANCODE_A] = angle_left;
	sdl->do_key[SDL_SCANCODE_D] = angle_right;
}

void				sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (ft_crash(SDL_GetError()));
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		return (ft_crash(SDL_GetError()));
	if (!(sdl->win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		return (ft_crash(SDL_GetError()));
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1,
			SDL_RENDERER_ACCELERATED)))
		return (ft_crash(SDL_GetError()));
	if (!(sdl->texture = SDL_CreateTexture(sdl->ren,
			SDL_GetWindowPixelFormat(sdl->win),
			SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT)))
		return (ft_crash(SDL_GetError()));
	keys_init(sdl->keys);
	functions_init(sdl);
	sdl->running = 1;
}
