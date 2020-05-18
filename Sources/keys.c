/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:11:46 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/18 21:24:14 by wstygg           ###   ########.fr       */
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

	new_x = SDL_cos(wolf->player.a) * (keys[SDL_SCANCODE_LSHIFT] ? 0.15 : 0.1);
	new_y = SDL_sin(wolf->player.a) * (keys[SDL_SCANCODE_LSHIFT] ? 0.15 : 0.1);
	if (!is_wall(wolf->player.x + new_x, wolf->player.y, wolf->map.map))
		wolf->player.x += new_x;
	if (!is_wall(wolf->player.x, wolf->player.y + new_y, wolf->map.map))
		wolf->player.y += new_y;
}

void			move_backward(t_wolf *wolf, const int *keys)
{
	double		new_x;
	double		new_y;

	new_x = SDL_cos(wolf->player.a) * (keys[SDL_SCANCODE_LSHIFT] ? 0.15 : 0.1);
	new_y = SDL_sin(wolf->player.a) * (keys[SDL_SCANCODE_LSHIFT] ? 0.15 : 0.1);
	if (!is_wall(wolf->player.x - new_x, wolf->player.y, wolf->map.map))
		wolf->player.x -= new_x;
	if (!is_wall(wolf->player.x, wolf->player.y - new_y, wolf->map.map))
		wolf->player.y -= new_y;
}

void			angle_left(t_wolf *wolf, const int *keys)
{
	wolf->player.a -= 0.025 * (keys[SDL_SCANCODE_LSHIFT] ? 1.5 : 1);
}

void			angle_right(t_wolf *wolf, const int *keys)
{
	wolf->player.a += 0.025 * (keys[SDL_SCANCODE_LSHIFT] ? 1.5 : 1);
}
