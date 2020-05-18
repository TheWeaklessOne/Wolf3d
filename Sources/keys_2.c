/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 20:40:04 by wstygg            #+#    #+#             */
/*   Updated: 2020/05/18 20:47:28 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		add_dist(t_wolf *wolf, const int *keys)
{
	(void)keys;
	if (wolf->ray_dist < 200)
		wolf->ray_dist += 1;
}

void		sub_dist(t_wolf *wolf, const int *keys)
{
	(void)keys;
	if (wolf->ray_dist > 1)
		wolf->ray_dist -= 1;
}