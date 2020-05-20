/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:11:46 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/20 15:53:10 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		is_wall(const double x, const double y, char **wall)
{
	const char	c = wall[(int)y][(int)x];

	return (c >= CHAR_WALL_1 && c < CHAR_WALLS_END);
}

void			move_forward(t_wolf *wolf, const int *keys)
{
	double		new_x;
	double		new_y;
	double		min_dist;

	min_dist = 0.2;
	new_x = SDL_cos(wolf->player.a) * (keys[SDL_SCANCODE_LSHIFT] ? 0.0050 : 0.0025) * ft_time()->delta;
	new_y = SDL_sin(wolf->player.a) * (keys[SDL_SCANCODE_LSHIFT] ? 0.0050 : 0.0025) * ft_time()->delta;
	if (new_x < 0)
		min_dist *= -1;
	if (!is_wall(wolf->player.x + new_x + min_dist, wolf->player.y, wolf->map.map))
		wolf->player.x += new_x;
	min_dist = 0.2;
	if (new_y < 0)
		min_dist *= -1;
	if (!is_wall(wolf->player.x, wolf->player.y + new_y + min_dist, wolf->map.map))
		wolf->player.y += new_y;
}

void			move_backward(t_wolf *wolf, const int *keys)
{
	double		new_x;
	double		new_y;
	double		min_dist;

	min_dist = 0.2;
	new_x = SDL_cos(wolf->player.a) * (keys[SDL_SCANCODE_LSHIFT] ? 0.0050 : 0.0025) * ft_time()->delta;
	new_y = SDL_sin(wolf->player.a) * (keys[SDL_SCANCODE_LSHIFT] ? 0.0050 : 0.0025) * ft_time()->delta;
	if (new_x < 0)
		min_dist *= -1;
	if (!is_wall(wolf->player.x - new_x - min_dist, wolf->player.y, wolf->map.map))
		wolf->player.x -= new_x;
	min_dist = 0.2;
	if (new_y < 0)
		min_dist *= -1;
	if (!is_wall(wolf->player.x, wolf->player.y - new_y - min_dist, wolf->map.map))
		wolf->player.y -= new_y;
}

void			angle_left(t_wolf *wolf, const int *keys)
{
	wolf->player.a -= 0.025 * (keys[SDL_SCANCODE_LSHIFT] ? 0.12 : 0.075) * ft_time()->delta;
}

void			angle_right(t_wolf *wolf, const int *keys)
{
	wolf->player.a += 0.025 * (keys[SDL_SCANCODE_LSHIFT] ? 0.12 : 0.075) * ft_time()->delta;
}
