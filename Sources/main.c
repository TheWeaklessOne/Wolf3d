/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:05:44 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/17 18:04:21 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static unsigned		get_wall_color(const char c, t_list **walls)
{
	t_texture		*tex;

	tex = NULL;
	if (c == CHAR_WALL_1)
		tex = walls[0]->content;
	else if (c == CHAR_WALL_2)
		tex = walls[1]->content;
	else if (c == CHAR_WALL_3)
		tex = walls[2]->content;
	return (tex->pixels[0]);
}

static void			draw_rectangle(const t_rect rect, const unsigned color,
									unsigned  *pixels)
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

static void			set_pixel(const int x, const int y, const unsigned color,
								unsigned *pixels)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		pixels[x + y * WIDTH] = color;
}

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

static void			render(const t_wolf wolf, t_sdl *sdl)
{
	register int	i;
	register double	t;
	double			cx;
	double			cy;
	double			angle;
	unsigned 		column_h;

	i = -1;
	while (++i < WIDTH)
	{
		angle = wolf.player.a - wolf.player.fov / 2 + wolf.player.fov * i / WIDTH;
		t = -0.06;
		while ((t += 0.06) < 20.0)
		{
			cx = wolf.player.x + t * SDL_cos(angle);
			cy = wolf.player.y + t * SDL_sin(angle);
			if (wolf.show_map)
				set_pixel((int)(cx * wolf.map.rect_w),
						  (int)(cy * wolf.map.rect_h), 0xFFFFFF, sdl->pixels);
			if (wolf.map.map[(int)cy][(int)cx] != CHAR_EMPTY)
			{
				column_h = HEIGHT / (t * SDL_cos(angle - wolf.player.a));
				draw_rectangle((t_rect){i, HEIGHT / 2 - column_h / 2, 1, column_h}, get_wall_color(wolf.map.map[(int)cy][(int)cx], sdl->walls), sdl->pixels);
				break ;
			}
		}
	}
	if (wolf.show_map)
		map_render(wolf.map, sdl->pixels);
}

static void			draw_wall(t_list *wall, unsigned *pixels)
{
	register int	w;
	register int	h;
	t_texture		tex;

	h = -1;
	tex = *(t_texture*)wall->content;
	while (++h < tex.h && (w = -1))
		while (++w < tex.w)
		{
			pixels[w + h * WIDTH] = tex.pixels[w + h * tex.h];
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
			manage_event(e, &sdl, &wolf);
		manage_keys(&sdl, &wolf);
		render_clear(sdl.pixels);
		render(wolf, &sdl);
		SDL_UpdateTexture(sdl.texture, NULL, sdl.pixels, PITCH);
		SDL_RenderCopy(sdl.ren, sdl.texture, NULL, NULL);
		SDL_RenderPresent(sdl.ren);
	}
	sdl_quit(&sdl);
	exit(0);
}