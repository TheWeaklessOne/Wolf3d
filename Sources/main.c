/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:05:44 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/14 14:27:13 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			draw_rectangle(const int img_w, const int img_h, const int x, const int y, const int w, const int h, unsigned color, unsigned  *pixels)
{
	register int	i;
	register int	j;
	int cx;
	int cy;

	i = -1;
	while (++i < w && (j = -1))
		while (++j < h)
		{
			cx = x + i;
			cy = y + j;
			if (cx>=img_w || cy>=img_h)
				continue;
			pixels[cx + cy*img_w] = color;
		}
}
//0x4cd4ab

static void			render(unsigned *pixels, const t_wolf wolf)
{
	const size_t win_w = 1024; // image width
	const size_t win_h = 512;  // image height

	const size_t map_w = 16; // map width
	const size_t map_h = 16; // map height

	float player_x = 3.456; // player x position
	float player_y = 2.345; // player y position
	float player_a = 1.8f; // player view direction
	const float fov = M_PI/3.; // field of view

	const size_t rect_w = win_w/(map_w*2);
	const size_t rect_h = win_h/map_h;
	for (size_t j=0; j<map_h; j++) { // draw the map
		for (size_t i=0; i<map_w; i++) {
			if (wolf.map[j][i] == CHAR_EMPTY)
				continue ; // skip empty spaces
			size_t rect_x = i*rect_w;
			size_t rect_y = j*rect_h;
			draw_rectangle(win_w, win_h, rect_x, rect_y, rect_w, rect_h, 0x4cd4ab, pixels);
		}
	}

	for (size_t i=0; i<win_w/2; i++) { // draw the visibility cone AND the "3D" view
		float angle = player_a-fov/2 + fov*i/(float)(win_w/2);
		for (float t=0; t<20; t+=.05) {
			float cx = player_x + t*SDL_cos(angle);
			float cy = player_y + t*SDL_sin(angle);

			size_t pix_x = cx*rect_w;
			size_t pix_y = cy*rect_h;
			pixels[pix_x + pix_y*win_w] = 0xFFFFFF; // this draws the visibility cone

			if (wolf.map[(int)cy][(int)cx] != CHAR_EMPTY)
			{
				size_t column_height = win_h/(t*SDL_cos(angle-player_a));
				draw_rectangle(win_w, win_h, win_w/2+i, win_h/2-column_height/2, 1, column_height, 0x4cd4ab, pixels);
				break;
			}
		}
	}

}

int					main(int argc, char *argv[])
{
	SDL_Event		e;
	t_sdl			sdl;
	t_wolf			wolf;

	wolf_init(&wolf, argc, argv);
	sdl_init(&sdl);
	while (sdl.running)
	{
		while (SDL_PollEvent(&e))
			manage_event(e, &sdl);
		manage_keys(&sdl, &wolf);
		render_clear(sdl.pixels);
		render(sdl.pixels, wolf);
		SDL_UpdateTexture(sdl.texture, NULL, sdl.pixels, WIDTH * 4);
		SDL_RenderCopy(sdl.ren, sdl.texture, NULL, NULL);
		SDL_RenderPresent(sdl.ren);
	}
	sdl_quit(&sdl);
	exit(0);
}