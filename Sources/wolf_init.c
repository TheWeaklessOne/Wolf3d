/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:23:34 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/13 22:57:55 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void					wolf_init(t_wolf *wolf, int argc, char *argv[])
{
	if (argc != 2)
		ft_crash("Using: ./wolf3d [Map]");
	wolf->map_h = 0;
	wolf->map_w = 0;
	read_map(argv[1], wolf);
}
