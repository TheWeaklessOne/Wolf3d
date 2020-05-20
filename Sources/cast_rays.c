/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 00:40:43 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 16:24:03 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static unsigned		*get_column(const unsigned column_h,
								const t_texture texture, const int x_coord)
{
	register int	i;
	unsigned		*column;

	i = -1;
	if (!(column = malloc(sizeof(unsigned) * column_h)))
		ft_crash("Column malloc error!");
	while (++i < column_h)
		column[i] = texture.pixels[x_coord + (i * texture.h / column_h)
							 			* texture.w];
	return (column);
}

static void			render_walls(const int i, const unsigned column_h,
									unsigned *column, unsigned *pixels)
{
	register int	j;

	j = -1;
	while (++j < column_h)
		set_pixel(i, j + HEIGHT_H - column_h / 2, column[j], pixels);
	free(column);
}

t_texture			get_texture(const t_xy xy, t_wolf *wolf, int *x_coord)
{
	int				side;
	double			hit_x;
	double			hit_y;
	t_list			*walls;
	t_texture		texture;

	hit_x = xy.x - SDL_floor(xy.x + 0.5);
	hit_y = xy.y - SDL_floor(xy.y + 0.5);
	if (SDL_fabs(hit_y) < 0.01 && hit_y < 0)
		side = 0;
	else if (SDL_fabs(hit_y) < 0.01 && hit_y > 0)
		side = 1;
	else if (SDL_fabs(hit_x) < 0.01 && hit_x < 0)
		side = 2;
	else
		side = 3;
	walls = wolf->walls[wolf->map.map[(int)xy.y][(int)xy.x] - CHAR_WALL_1].textures;
	texture = *((t_texture**)walls->content)[side];
	if (SDL_fabs(hit_y) > SDL_fabs(hit_x))
	{
		if ((*x_coord = hit_y * texture.h) < 0)
			*x_coord += texture.h;
	}
	else if ((*x_coord = hit_x * texture.w) < 0)
		*x_coord += texture.w;
	return (texture);
}

void				cast_rays(t_wolf *wolf, const double angle,
							  const int i, unsigned *pixels)
{
	register double	t;
	t_xy			xy;
	int				x_coord;
	t_texture		texture;
	unsigned		column_h;

	t = -wolf->ray_step;
	while ((t += wolf->ray_step) < wolf->ray_dist)
	{
		xy.x = wolf->player.x + t * SDL_cos(angle);
		xy.y = wolf->player.y + t * SDL_sin(angle);
		if (wolf->map.map[(int)xy.y][(int)xy.x] == CHAR_EMPTY)
		{
			if (wolf->show_map)
				set_pixel((int)(xy.x * wolf->map.rect_w),
						  (int)(xy.y * wolf->map.rect_h), 0xFFFFFF, pixels);
			continue ;
		}
		column_h = HEIGHT / (t * SDL_cos(angle - wolf->player.a));
		texture = get_texture(xy, wolf, &x_coord);
		render_walls(i, column_h, get_column(column_h, texture, x_coord), pixels);
		break ;
	}
}
