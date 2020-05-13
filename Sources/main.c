/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:05:44 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/13 16:25:37 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int					main(int argc, char *argv[])
{
	SDL_Event		e;
	t_sdl			sdl;
	t_wolf			wolf;

	sdl_init(&sdl);
	wolf.hero = (SDL_Rect){.w = 100, .h = 100};
	while (sdl.running)
	{
		while (SDL_PollEvent(&e))
			manage_event(e, &sdl);
		manage_keys(&sdl, &wolf);
		SDL_UpdateTexture(sdl.texture, NULL, sdl.pixels, WIDTH * 4);
		SDL_RenderCopy(sdl.ren, sdl.texture, NULL, NULL );
		SDL_SetRenderDrawColor(sdl.ren, 255, 255, 255, 255);
		SDL_RenderDrawRect(sdl.ren, &wolf.hero);
		SDL_RenderPresent(sdl.ren);
	}
	sdl_quit(&sdl);
	exit(0);
}