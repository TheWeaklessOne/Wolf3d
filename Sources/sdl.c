/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:28:35 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/13 16:31:02 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				manage_event(SDL_Event e, t_sdl *sdl)
{
	if (e.type == SDL_QUIT)
		sdl->running = 0;
	else if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_ESCAPE)
		{
			sdl->running = 0;
			return ;
		}
		if (!sdl->keys[e.key.keysym.scancode])
			sdl->keys[e.key.keysym.scancode] = 1;
	}
	else if (e.type == SDL_KEYUP)
		sdl->keys[e.key.keysym.scancode] = 0;
}

void				manage_keys(t_sdl *sdl, t_wolf * wolf)
{
	register int	i;

	i = -1;
	while (++i < SDL_NUM_SCANCODES)
		if (sdl->keys[i] && sdl->do_key[i])
			sdl->do_key[i](wolf);
}

void				sdl_quit(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	sdl->win = NULL;
	sdl->ren = NULL;
	IMG_Quit();
	SDL_Quit();
}
