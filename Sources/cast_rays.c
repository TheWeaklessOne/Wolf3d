/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 00:40:43 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/19 00:57:25 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int			get_x_coord(const double x, const double y,
								  const t_texture texture)
{
	double			hit_x;
	double			hit_y;
	int				x_coord;

	hit_x = x - SDL_floor(x + 0.5);
	hit_y = y - SDL_floor(y + 0.5);
	if (SDL_fabs(hit_y) > SDL_fabs(hit_x))
	{
		if ((x_coord = hit_y * texture.h) < 0)
			x_coord += texture.h;
	}
	else if ((x_coord = hit_x * texture.w) < 0)
		x_coord += texture.w;
	return (x_coord);
}

static unsigned		*get_column(const double x, const double y,
								const unsigned column_h,
								const t_texture texture)
{
	register int	i;
	unsigned		*column;

	i = -1;
	if (!(column = malloc(sizeof(unsigned) * column_h)))
		ft_crash("Column malloc error!");
	while (++i < column_h)
		column[i] = texture.pixels[get_x_coord(x, y, texture)
					+ (i * texture.h / column_h) * texture.w];
	return (column);
}

void			render_walls(const int i, const unsigned column_h,
								unsigned *column, unsigned *pixels)
{
	register int	j;

	j = -1;
	while (++j < column_h)
		set_pixel(i, j + HEIGHT_H - column_h/ 2, column[j], pixels);
	free(column);
}

void			cast_rays(const t_wolf wolf, const double angle,
						  const int i, unsigned *pixels)
{
	register double	t;
	double			x;
	double			y;
	unsigned		column_h;

	t = -wolf.ray_step;
	while ((t += wolf.ray_step) < wolf.ray_dist)
	{
		column_h = HEIGHT / (t * SDL_cos(angle - wolf.player.a));
		x = wolf.player.x + t * SDL_cos(angle);
		y = wolf.player.y + t * SDL_sin(angle);
		if (wolf.show_map)
			set_pixel((int)(x * wolf.map.rect_w),
					  (int)(y * wolf.map.rect_h), 0xFFFFFF, pixels);
		if (wolf.map.map[(int)y][(int)x] == CHAR_EMPTY)
			continue ;
		render_walls(i, column_h, get_column(x, y, column_h, *(t_texture*)wolf.
		walls[wolf.map.map[(int)y][(int)x] - CHAR_WALL_1]->content), pixels);
		break ;
	}
}
