/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:11:46 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/17 15:17:49 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				move_forward(t_wolf *wolf, const int *keys)
{
	const double	new_x = SDL_cos(wolf->player.a) *
			(keys[SDL_SCANCODE_LSHIFT] ? 0.15 : 0.1);
	const double	new_y = SDL_sin(wolf->player.a) *
			(keys[SDL_SCANCODE_LSHIFT] ? 0.15 : 0.1);
	const char		c = wolf->map.map[(int)(wolf->player.y + new_y)]
									[(int)(wolf->player.x + new_x)];

	if (c < CHAR_WALL_1 || c >= CHAR_WALLS_N)
	{
		wolf->player.x += new_x;
		wolf->player.y += new_y;
	}
}

void				move_backward(t_wolf *wolf, const int *keys)
{
	const double	new_x = SDL_cos(wolf->player.a) *
			(keys[SDL_SCANCODE_LSHIFT] ? 0.15 : 0.1);
	const double	new_y = SDL_sin(wolf->player.a) *
			(keys[SDL_SCANCODE_LSHIFT] ? 0.15 : 0.1);
	const char		c = wolf->map.map[(int)(wolf->player.y - new_y)]
	[(int)(wolf->player.x - new_x)];

	if (c < CHAR_WALL_1 || c >= CHAR_WALLS_N)
	{
		wolf->player.x -= new_x;
		wolf->player.y -= new_y;
	}
}

void				angle_left(t_wolf *wolf, const int *keys)
{
	wolf->player.a -= 0.025 * (keys[SDL_SCANCODE_LSHIFT] ? 1.5 : 1);
}

void			angle_right(t_wolf *wolf, const int *keys)
{
	wolf->player.a += 0.025 * (keys[SDL_SCANCODE_LSHIFT] ? 1.5 : 1);
}
