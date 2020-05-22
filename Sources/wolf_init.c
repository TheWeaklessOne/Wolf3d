/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:23:34 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/22 02:09:33 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void					wolf_init(t_wolf *wolf, const int argc, char *argv[])
{
	if (argc != 2)
		ft_crash("Using: ./wolf3d [Map]");
	wolf->map.map_h = 0;
	wolf->map.map_w = 0;
	wolf->player.a = 1.53;
	wolf->player.fov = M_PI / 3;
	wolf->ray_dist = RAY_DIST_DEF;
	wolf->ray_step = RAY_STEP_DEF;
	read_map(argv[1], &wolf->map, &wolf->player);
	wolf->show_map = wolf->map.map_w == wolf->map.map_h;
	wolf->roof_c = ROOF_COLOR;
	wolf->floor_c = FLOOR_COLOR;
}
