/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:28:35 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/19 16:20:35 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				draw_rectangle(const t_rect rect,
							   const unsigned color, unsigned  *pixels)
{
	register int	i;
	register int	j;
	unsigned		cx;
	unsigned		cy;

	j = -1;
	while (++j < rect.h && (i = -1))
		while (++i < rect.w)
		{
			cx = rect.x + i;
			cy = rect.y + j;
			if (cx < WIDTH && cy < HEIGHT)
				pixels[cx + cy * WIDTH] = color;
		}
}

void				set_pixel(const unsigned x, const unsigned y,
						  const unsigned color, unsigned *pixels)
{
	if (x < WIDTH && y < HEIGHT)
		pixels[x + y * WIDTH] = color;
}

void				manage_event(const SDL_Event e, t_sdl *sdl, t_wolf *wolf)
{
	if (e.type == SDL_QUIT)
		sdl->running = 0;
	else if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_ESCAPE)
			sdl->running = 0;
		else if (e.key.keysym.sym == SDLK_m)
			wolf->show_map = !wolf->show_map;
		else if (e.key.keysym.sym == SDLK_m)
			wolf->show_map = !wolf->show_map;
		if (!sdl->keys[e.key.keysym.scancode])
			sdl->keys[e.key.keysym.scancode] = 1;
	}
	else if (e.type == SDL_KEYUP)
		sdl->keys[e.key.keysym.scancode] = 0;
}

void				manage_keys(t_sdl *sdl, t_wolf *wolf)
{
	register int	i;

	i = -1;
	while (++i < SDL_NUM_SCANCODES)
		if (sdl->keys[i] && sdl->do_key[i])
			sdl->do_key[i](wolf, sdl->keys);
}

void				sdl_quit(t_sdl *sdl)
{
	SDL_DestroyWindow(sdl->win);
	sdl->win = NULL;
	IMG_Quit();
	SDL_Quit();
}
