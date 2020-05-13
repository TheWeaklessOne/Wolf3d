/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:26:01 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/13 16:21:21 by wstygg           ###   ########.fr       */
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

static void			pixels_init(unsigned pixels[WIDTH * HEIGHT])
{
	register int	i;

	i = WIDTH * HEIGHT;
	while (--i >= 0)
		pixels[i] = 0;
}

static void			functions_init(t_sdl *sdl)
{
	register int	i;

	i = -1;
	while (++i < SDL_NUM_SCANCODES)
		sdl->do_key[i] = NULL;
	sdl->do_key[SDL_SCANCODE_W] = move_up;
	sdl->do_key[SDL_SCANCODE_S] = move_down;
	sdl->do_key[SDL_SCANCODE_A] = move_left;
	sdl->do_key[SDL_SCANCODE_D] = move_right;
}

void				sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (ft_crash(SDL_GetError()));
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		return (ft_crash(SDL_GetError()));
	if (!(sdl->win = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_CENTERED,
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
	pixels_init(sdl->pixels);
	functions_init(sdl);
	sdl->running = 1;
}
